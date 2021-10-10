-- create a simple table for storing first_name and last_name of persons.
create table if not exists persons (
  first_name text,
  last_name text
);

insert into persons values ('Elahe', 'Dastan');
insert into persons values ('Sara', 'Dastan');

alter table if exists persons add column if not exists id text;

insert into persons values ('Negin', 'Amjadi', '0017784646');

create view persons_name_view as select first_name, last_name from persons;
