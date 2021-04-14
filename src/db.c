/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <sqlite3.h>
#include "db.h"
#include "map.h"
#include "common.h"

void db_init()
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc;

    rc = sqlite3_open(DB_FILE, &db);
    if(rc) {
        printf("Error: Could not open database %s\n%s\n", DB_FILE, sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, "SELECT * FROM rooms", map_load, 0, &err_msg);
    if(rc != SQLITE_OK) {
        printf("Error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}
