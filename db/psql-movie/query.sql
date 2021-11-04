create extension if not exists tablefunc;

select store.store_id, category.name, count(film.film_id) from store, rental, film, inventory, staff, film_category, category where
  store.store_id = staff.store_id and rental.staff_id = staff.staff_id and
  rental.inventory_id = inventory.inventory_id and inventory.film_id = film_category.film_id and
  film_category.film_id = category.category_id
  group by store.store_id, category.name order by store_id;

select * from crosstab(
  'select store.store_id, category.category_id, count(film.film_id) from store, rental, film, inventory, staff, film_category, category where
  store.store_id = staff.store_id and rental.staff_id = staff.staff_id and
  rental.inventory_id = inventory.inventory_id and inventory.film_id = film_category.film_id and
  film_category.film_id = category.category_id
  group by store.store_id, category.category_id order by store_id',
  'select category_id from category limit 2'
) as (store int, cat1 int, cat2 int);

select film.film_id, payment.yyear, payment.mmonth, payment.dday, sum(payment.amount) from
  film, rental,
  (select amount, rental_id, extract(year from payment_date) as yyear, extract(month from payment_date) as mmonth, extract(day from payment_date) as dday from payment) as payment, inventory
  where film.film_id = inventory.film_id and inventory.inventory_id = rental.inventory_id and payment.rental_id = rental.rental_id
  group by film.film_id, payment.yyear, payment.mmonth, payment.dday
  order by film.film_id;

select film.film_id, payment.yyear, payment.mmonth, payment.dday, sum(payment.amount) from
  film, rental,
  (select amount, rental_id, extract(year from payment_date) as yyear, extract(month from payment_date) as mmonth, extract(day from payment_date) as dday from payment) as payment, inventory
  where film.film_id = inventory.film_id and inventory.inventory_id = rental.inventory_id and payment.rental_id = rental.rental_id
  group by rollup(film.film_id, payment.yyear, payment.mmonth, payment.dday)
  order by film.film_id;

select film.film_id, payment.yyear, payment.mmonth, payment.dday, sum(payment.amount) from
  film, rental,
  (select amount, rental_id, extract(year from payment_date) as yyear, extract(month from payment_date) as mmonth, extract(day from payment_date) as dday from payment) as payment, inventory
  where film.film_id = inventory.film_id and inventory.inventory_id = rental.inventory_id and payment.rental_id = rental.rental_id
  group by cube(film.film_id, payment.yyear, payment.mmonth, payment.dday)
  order by film.film_id;

select film.title, category.name, film.length, rank () over ( partition by category.name order by length )
  from category, film, film_category where film.film_id = film_category.film_id and film_category.category_id = category.category_id;
