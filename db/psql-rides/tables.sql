create type ride_event as enum ('ride_requested', 'ride_accepted', 'ride_boarded', 'ride_finished', 'ride_not_accepted', 'ride_cancelled');

create table if not exists rides (
        id bigint,
        event_name ride_event not null,
        created_at timestamp not null default now()
);

-- successful ride
insert into rides (id, event_name) values (1, 'ride_requested');
insert into rides (id, event_name) values (1, 'ride_accepted');
insert into rides (id, event_name) values (1, 'ride_boarded');
insert into rides (id, event_name) values (1, 'ride_finished');

-- not accepted ride
insert into rides (id, event_name) values (2, 'ride_requested');
insert into rides (id, event_name) values (2, 'ride_not_accepted');

-- cancelled ride
insert into rides (id, event_name) values (3, 'ride_requested');
insert into rides (id, event_name) values (3, 'ride_cancelled');

-- cancelled ride
insert into rides (id, event_name) values (4, 'ride_requested');
insert into rides (id, event_name) values (4, 'ride_accepted');
insert into rides (id, event_name) values (4, 'ride_cancelled');
