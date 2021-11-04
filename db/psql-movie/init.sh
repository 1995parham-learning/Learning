#!/bin/bash

set -e

pg_restore --username "$POSTGRES_USER" --dbname "$POSTGRES_DB" dvdrental.tar
