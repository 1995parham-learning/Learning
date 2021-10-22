create type ride_event as enum ('ride_requested', 'ride_accepted', 'ride_boarded', 'ride_finished', 'ride_not_accepted', 'ride_cancelled');

create table if not exists passengers (
        id serial primary key,
        first_name text,
        last_name text,
        national_id text
);

create table if not exists drivers (
        id serial primary key,
        first_name text,
        last_name text,
        national_id text
);

create table if not exists rides (
        id bigint,
        passenger_id int default null references passengers(id),
        driver_id int default null references drivers(id),
        event_name ride_event not null,
        created_at timestamp not null default now()
);

-- passengers
insert into passengers (first_name, last_name, national_id) values ('Test1', 'Passenger', '1234');
insert into passengers (first_name, last_name, national_id) values ('Test2', 'Passenger', '1235');

-- drivers
insert into drivers (first_name, last_name, national_id) values ('Test1', 'Driver', '1234');
insert into drivers (first_name, last_name, national_id) values ('Test2', 'Driver', '1235');
insert into drivers (first_name, last_name, national_id) values ('Test2', 'Passenger', '1235');

-- successful ride
insert into rides (id, passenger_id, event_name) values (1, 1, 'ride_requested');
insert into rides (id, passenger_id, driver_id, event_name) values (1, 1, 1, 'ride_accepted');
insert into rides (id, passenger_id, driver_id, event_name) values (1, 1, 1, 'ride_boarded');
insert into rides (id, passenger_id, driver_id, event_name) values (1, 1, 1, 'ride_finished');

-- not accepted ride
insert into rides (id, passenger_id, event_name) values (2, 1, 'ride_requested');
insert into rides (id, passenger_id, event_name) values (2, 1, 'ride_not_accepted');

-- cancelled ride
insert into rides (id, passenger_id, event_name) values (3, 1, 'ride_requested');
insert into rides (id, passenger_id, event_name) values (3, 1, 'ride_cancelled');

-- cancelled ride
insert into rides (id, passenger_id, event_name) values (4, 1, 'ride_requested');
insert into rides (id, passenger_id, driver_id, event_name) values (4, 1, 1, 'ride_accepted');
insert into rides (id, passenger_id, driver_id, event_name) values (4, 1, 1, 'ride_cancelled');
