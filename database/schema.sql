-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2025-05-26 11:24:05.324

-- Table: buses
CREATE TABLE buses (
    id integer NOT NULL CONSTRAINT buses_pk PRIMARY KEY,
    number varchar(20) NOT NULL,
    model varchar(50) NOT NULL,
    mileage real NOT NULL,
    CONSTRAINT number UNIQUE (number)
);

-- Table: routes
CREATE TABLE routes (
    id integer NOT NULL CONSTRAINT routes_pk PRIMARY KEY,
    name varchar(100) NOT NULL,
    start_point varchar(100) NOT NULL,
    end_point varchar(100) NOT NULL,
    distance real NOT NULL
);

-- Table: crews
CREATE TABLE crews (
    id integer NOT NULL CONSTRAINT crews_pk PRIMARY KEY,
    last_name varchar(50) NOT NULL,
    personnel_number varchar(20) NOT NULL,
    experience integer NOT NULL,
    bus_id integer NOT NULL,
    CONSTRAINT personnel_number UNIQUE (personnel_number),
    CONSTRAINT crews_buses_fk FOREIGN KEY (bus_id)
    REFERENCES buses (id)
);

-- Table: trips
CREATE TABLE trips (
    id integer NOT NULL CONSTRAINT trips_pk PRIMARY KEY,
    bus_id integer NOT NULL,
    route_id integer NOT NULL,
    departure_date date NOT NULL,
    arrival_date date NOT NULL,
    passengers integer NOT NULL,
    ticket_price real NOT NULL,
    CONSTRAINT trips_buses_fk FOREIGN KEY (bus_id)
    REFERENCES buses (id),
    CONSTRAINT trips_routes_fk FOREIGN KEY (route_id)
    REFERENCES routes (id)
);