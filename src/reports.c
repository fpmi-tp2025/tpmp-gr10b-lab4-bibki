// reports.c
#include "reports.h"
#include <stdio.h>

void generate_crew_report(sqlite3 *db, const char *personnel_number) {
    sqlite3_stmt *stmt;
    const char *sql = 
        "SELECT SUM(ticket_price * passengers * 0.2) "
        "FROM trips t JOIN crews c ON t.bus_id = c.bus_id "
        "WHERE c.personnel_number = ?";
    
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, personnel_number, -1, SQLITE_STATIC);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("Заработок экипажа: %.2f\n", sqlite3_column_double(stmt, 0));
    }
    
    sqlite3_finalize(stmt);
}
