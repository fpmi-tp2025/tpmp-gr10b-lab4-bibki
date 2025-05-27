// auth.c
#include "auth.h"
#include <stdio.h>
#include <string.h>

int authenticate(sqlite3 *db, const char *personnel_number, Role *role) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT role FROM crews WHERE personnel_number = ?";
    
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Auth error: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    
    sqlite3_bind_text(stmt, 1, personnel_number, -1, SQLITE_STATIC);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        *role = (Role)sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return 1;
    }
    
    sqlite3_finalize(stmt);
    return 0;
}
