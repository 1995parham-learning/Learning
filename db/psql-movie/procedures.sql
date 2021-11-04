-- read phone number as a text and then detects its type, city and reports them.
create or replace procedure phone (
  phone_number text
) language plpgsql as $$
begin
  if phone_number like '0912%' then
    raise info 'mobile phone number';
  elseif phone_number like '021%' then
    raise info 'city=tehran,city code=021,last 8 digits=%', substring(phone_number, 4, 8);
  elseif phone_number like '031%' then
    raise info 'city=esfahan,city code=031,last 8 digits=%', substring(phone_number, 4, 8);
  end if;
end
$$;

-- reports films that are rented between given dates
create or replace function renteds (
  in begin_date date,
  in end_date date
)
returns table(title varchar(255), film_id int)
language plpgsql as $$
begin
  return query
    select
      film.title,
      film.film_id
    from
      rental,
      inventory,
      film
    where
      rental.rental_id = inventory.inventory_id
      and
      inventory.film_id = film.film_id
      and
      rental.rental_date > begin_date
      and
      rental.rental_date < end_date;
end
$$;

-- reports customers that rent films rented between given dates but do not return them
create or replace function bad_customers (
  in begin_date date,
  in end_date date
)
returns table(customer_id smallint)
language plpgsql as $$
begin
  return query
    select
      rental.customer_id
    from
      renteds(begin_date, end_date),
      inventory,
      rental,
      film
    where
      rental.rental_id = inventory.inventory_id
      and
      inventory.film_id = renteds.film_id
      and
      rental.return_date is null;
end
$$;

-- log table collects the status of rentals
create table if not exists rental_logs (
  customer_id smallint,
  duration interval
);

-- procedure will be called on insert or update of rental table to calculate the rent duration.
create or replace function on_rental_procedure () returns trigger language plpgsql as $$
declare
  film_duration interval;
  actual_duration interval;
begin
  select film.rental_duration into film_duration from film, inventory where inventory.inventory_id = NEW.inventory_id and inventory.film_id = film.film_id;
  select NEW.return_date - NEW.rental_date into actual_duration;

  if actual_duration > film_duration then
    insert into rental_logs values (NEW.customer_id, actual_duration);
  end if;
end
$$;

-- trigger that check the rent duration for rental_logs tbale.
create trigger on_rental
  before insert or update on rental
  execute procedure on_rental_procedure();

-- update every film row to increase rent duration.
create or replace procedure increase_duration (
  inc int
) language plpgsql as $$
begin
  update film set rental_duration = rental_duration + inc;
end
$$;
