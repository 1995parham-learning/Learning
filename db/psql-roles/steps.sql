create database elahe;

create table psersons (
  id int,
  name text,
  username text
);

insert into persons values (1, 'Elahe Dastan', 'eldaa');
insert into persons values (2, 'Sara Dastan', 'sdaa');
insert into persons values (3, 'Negin Amjadi', 'nj');
insert into persons values (4, 'John Duo', 'john');

-- create superuser
create role superman login superuser password 'suerpman';
-- print current user;
select current_user;

-- create role the_group with role creation permission and password expiration
create role the_group createrole valid until '25 Apr 2045';

-- create testrole1 and testrole2
create role testrole1 login password 'login1';
create role testrole2 login password 'login2';

-- join testrole1 and testrole2 to the_group role;
grant the_group to testrole1;
grant the_group to testrole2;

-- enable inheritance on testrole1
alter role testrole1 inherit;
-- ignore row level security  on testrole1
alter role testrole1 bypassrls;

-- change role name
alter role testrole2 rename to newtestrole2;

-- grant testrole1 to select on persons;
grant select on persons to testrole1;

-- enable row level security on persons
alter table persons enable row level security;
-- create policy on persons
create policy persons_policy on persons for select using (id > 3);

-- delete newtestrole2
drop role newtestrole2;
