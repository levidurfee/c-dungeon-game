/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2021 Levi Durfee <levi@x6c.us>
 */

#include <stdio.h>
#include <sqlite3.h>

#ifndef _DB_H
#define _DB_H

#define DB_FILE "./files/map.db"

void db_init();

#endif /* _DB_H */
