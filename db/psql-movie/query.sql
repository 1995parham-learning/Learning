create extension if not exists tablefunc;

select store.store_id, category.name, count(film.film_id) from store, rental, film, inventory, staff, film_category, category where
  store.store_id = staff.store_id and rental.staff_id = staff.staff_id and
  rental.inventory_id = inventory.inventory_id and inventory.film_id = film_category.film_id and
  film_category.film_id = category.category_id
  group by store.store_id, category.name order by store_id;

select * from crosstab(
  'select store.store_id, category.name, count(film.film_id) from store, rental, film, inventory, staff, film_category, category where
  store.store_id = staff.store_id and rental.staff_id = staff.staff_id and
  rental.inventory_id = inventory.inventory_id and inventory.film_id = film_category.film_id and
  film_category.film_id = category.category_id
  group by store.store_id, category.name order by store_id',
  'select "1"'
) as categories(one int);
