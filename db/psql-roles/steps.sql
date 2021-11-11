create database elahe;

create table psersons (
  id int,
  name text,
  username text
);

create role superman login superuser password 'suerpman';

create role the_group createrole valid until '25 Apr 2045';

create role testrole1 login password 'login1';
create role testrole2 login password 'login2';

grant the_group to testrole1;
grant the_group to testrole2;
