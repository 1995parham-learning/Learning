-- passengers that has a same driver for all of their rides since 1995-02-20
select * from passengers where exists (select id from drivers where id = all (select driver_id from rides where event_name = 'ride_accepted' and passenger_id = passengers.id and created_at > '1995-02-10'));

-- passengers who their name start with a T and cancell their rides
select * from passengers where id = any (select passenger_id from rides where event_name = 'ride_cancelled' and driver_id is null) and first_name like 'T%';
