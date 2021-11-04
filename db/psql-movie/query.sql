create extension if not exists tablefunc;

select store.store_id, category.name from store, rental, film, inventory, staff, film_category, category where
  store.store_id = staff.store_id and rental.staff_id = staff.staff_id and
  rental.inventory_id = inventory.inventory_id and inventory.film_id = film_category.film_id and
  film_category.film_id = category.category_id;

select * from crosstab(
  'select store.store_id, category.name, category.id from store, rental, film, inventory, staff, film_category, category where
  store.store_id = staff.store_id and rental.staff_id = staff.staff_id and
  rental.inventory_id = inventory.inventory_id and inventory.film_id = film_category.film_id and
  film_category.film_id = category.category_id',
  'select "1"'
) as categories(one int);

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
returns table(title varchar(255))
language plpgsql as $$
begin
  return query
    select
      film.title
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
