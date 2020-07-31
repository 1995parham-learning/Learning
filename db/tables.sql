/*
 * In The Name of God
 * =======================================
 * [] File Name : tables.sql
 *
 * [] Creation Date : 01-08-2020
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2020 Parham Alvani.
*/
create table if not exists users (
        id serial primary key,
        first_name text not null,
        last_name text not null,
        created_at timestamp not null default now(),
        phone text not null
);
