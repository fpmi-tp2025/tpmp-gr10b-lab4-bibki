#ifndef AUTH_H
#define AUTH_H

#include <sqlite3.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ADMIN = 0, CREW = 1 } Role;  // Явное указание значений

int authenticate(sqlite3 *db, const char *personnel_number, Role *role);
void logout();

#ifdef __cplusplus
}
#endif

#endif // AUTH_H

