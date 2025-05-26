INSERT INTO buses (number, model, mileage) VALUES 
('AB123', 'Mercedes Tourismo', 45000.5),
('CD456', 'Volvo 9700', 32000.0);

INSERT INTO routes (name, start_point, end_point, distance) VALUES
('Морской круиз', 'Главный вокзал', 'Порт', 15.5),
('Горный маршрут', 'Центр города', 'Горнолыжный курорт', 120.0);

INSERT INTO crews (last_name, personnel_number, experience, bus_id) VALUES
('Иванов', 'EMP001', 5, 1),
('Петров', 'EMP002', 3, 2);

INSERT INTO trips (bus_id, route_id, departure_date, arrival_date, passengers, ticket_price) VALUES
(1, 1, '2025-05-01', '2025-05-01', 25, 1500.0),
(2, 2, '2025-05-02', '2025-05-02', 30, 2500.0);
