// reports.h
#ifndef REPORTS_H
#define REPORTS_H

#include <sqlite3.h>

void generate_crew_report(sqlite3 *db, const char *personnel_number);

#endif
