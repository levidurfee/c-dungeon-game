CREATE TABLE "rooms" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"name"	TEXT,
	"description"	TEXT,
	"north"	INTEGER,
	"west"	INTEGER,
	"east"	INTEGER,
	"south"	INTEGER
);

CREATE UNIQUE INDEX "pk_id" ON "rooms" (
	"id"	ASC
);
