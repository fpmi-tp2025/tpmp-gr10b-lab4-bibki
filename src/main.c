#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#include "database.h"

// Database initialization: create tables if they don't exist
void init_db(sqlite3 *db) {
    const char *bus_table_sql =
        "CREATE TABLE IF NOT EXISTS buses ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "number TEXT NOT NULL,"
        "model TEXT NOT NULL,"
        "mileage REAL DEFAULT 0);";

    const char *route_table_sql =
        "CREATE TABLE IF NOT EXISTS routes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "start TEXT NOT NULL,"
        "end TEXT NOT NULL,"
        "distance REAL);";

    char *err_msg = NULL;

    if (sqlite3_exec(db, bus_table_sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Error creating buses table: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    if (sqlite3_exec(db, route_table_sql, 0, 0, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "Error creating routes table: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// Menu in English
void show_menu() {
    printf("\n=== Travel Agency Menu ===\n");
    printf("1. Add a bus\n");
    printf("2. Delete a bus\n");
    printf("3. Update bus mileage\n");
    printf("4. Show all buses\n");
    printf("5. Add a route\n");
    printf("6. Delete a route\n");
    printf("7. Update route distance\n");
    printf("8. Show all routes\n");
    printf("0. Exit\n");
    printf("Select an action: ");
}

int main() {
    sqlite3 *db;
    if (sqlite3_open("../database/tourism.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    init_db(db);

    int choice;
    do {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear input
            continue;
        }

        switch (choice) {
            case 1: {
                char number[50], model[50];
                printf("Enter bus number: ");
                scanf("%s", number);
                printf("Enter bus model: ");
                scanf("%s", model);
                add_bus(db, number, model);
                break;
            }
            case 2: {
                int id;
                printf("Enter bus ID to delete: ");
                scanf("%d", &id);
                delete_bus(db, id);
                break;
            }
            case 3: {
                int id;
                float mileage;
                printf("Enter bus ID: ");
                scanf("%d", &id);
                printf("Enter new mileage: ");
                scanf("%f", &mileage);
                update_bus_mileage(db, id, mileage);
                break;
            }
            case 4:
                print_all_buses(db);
                break;

            case 5: {
                char name[50], start[50], end[50];
                float distance;
                printf("Enter route name: ");
                scanf("%s", name);
                printf("Enter starting point: ");
                scanf("%s", start);
                printf("Enter destination: ");
                scanf("%s", end);
                printf("Enter distance: ");
                scanf("%f", &distance);
                add_route(db, name, start, end, distance);
                break;
            }
            case 6: {
                int id;
                printf("Enter route ID to delete: ");
                scanf("%d", &id);
                delete_route(db, id);
                break;
            }
            case 7: {
                int id;
                float distance;
                printf("Enter route ID: ");
                scanf("%d", &id);
                printf("Enter new distance: ");
                scanf("%f", &distance);
                update_route_distance(db, id, distance);
                break;
            }
            case 8:
                print_all_routes(db);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    sqlite3_close(db);
    return 0;
}