#include "database.h"
#include <stdio.h>
#include <stdlib.h>

// ================== Bus Operations ==================

void add_bus(sqlite3 *db, const char *number, const char *model) {
    char *err_msg = NULL;
    char *sql = sqlite3_mprintf(
        "INSERT INTO buses (number, model, mileage) VALUES ('%q', '%q', 0);",
        number, model
    );

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error (add_bus): %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_free(sql);
}

void delete_bus(sqlite3 *db, int id) {
    char *err_msg = NULL;
    char *sql = sqlite3_mprintf("DELETE FROM buses WHERE id = %d;", id);

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error (delete_bus): %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_free(sql);
}

void update_bus_mileage(sqlite3 *db, int id, float new_mileage) {
    char *err_msg = NULL;
    char *sql = sqlite3_mprintf(
        "UPDATE buses SET mileage = %f WHERE id = %d;",
        new_mileage, id
    );

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error (update_bus): %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_free(sql);
}

void print_all_buses(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT id, number, model, mileage FROM buses;";

    printf("\n=== Bus List ===\n");
    printf("ID\tNumber\tModel\t\tMileage\n");
    printf("--------------------------------\n");

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            printf("%d\t%s\t%s\t%.1f\n",
                sqlite3_column_int(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_text(stmt, 2),
                sqlite3_column_double(stmt, 3));
        }
    }
    sqlite3_finalize(stmt);
}

// ================== Route Operations ==================

void add_route(sqlite3 *db, const char *name, const char *start, const char *end, float distance) {
    char *err_msg = NULL;
    char *sql = sqlite3_mprintf(
        "INSERT INTO routes (name, start_point, end_point, distance) VALUES ('%q', '%q', '%q', %f);",
        name, start, end, distance
    );

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error (add_route): %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_free(sql);
}

void delete_route(sqlite3 *db, int id) {
    char *err_msg = NULL;
    char *sql = sqlite3_mprintf("DELETE FROM routes WHERE id = %d;", id);

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error (delete_route): %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_free(sql);
}

void update_route_distance(sqlite3 *db, int id, float new_distance) {
    char *err_msg = NULL;
    char *sql = sqlite3_mprintf(
        "UPDATE routes SET distance = %f WHERE id = %d;",
        new_distance, id
    );

    if (sqlite3_exec(db, sql, NULL, NULL, &err_msg) != SQLITE_OK) {
        fprintf(stderr, "SQL error (update_route): %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_free(sql);
}

void print_all_routes(sqlite3 *db) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT id, name, start_point, end_point, distance FROM routes;";

    printf("\n=== Route List ===\n");
    printf("ID\tName\t\tStart\t\tEnd\t\tDistance\n");
    printf("------------------------------------------------\n");

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            printf("%d\t%s\t%s\t%s\t%.1f km\n",
                sqlite3_column_int(stmt, 0),
                sqlite3_column_text(stmt, 1),
                sqlite3_column_text(stmt, 2),
                sqlite3_column_text(stmt, 3),
                sqlite3_column_double(stmt, 4));
        }
    }
    sqlite3_finalize(stmt);
}