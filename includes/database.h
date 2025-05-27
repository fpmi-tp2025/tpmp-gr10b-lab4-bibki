#ifndef DB_OPS_H
#define DB_OPS_H

#include <sqlite3.h>

// Bus operations
void add_bus(sqlite3 *db, const char *number, const char *model);
void delete_bus(sqlite3 *db, int id);
void update_bus_mileage(sqlite3 *db, int id, float new_mileage);
void print_all_buses(sqlite3 *db);

// Route operations
void add_route(sqlite3 *db, const char *name, const char *start, const char *end, float distance);
void delete_route(sqlite3 *db, int id);
void update_route_distance(sqlite3 *db, int id, float new_distance);
void print_all_routes(sqlite3 *db);

#endif