CREATE TABLE IF NOT EXISTS "Rooms" (
	"id_rooms"	TEXT NOT NULL,
	"name"	TEXT NOT NULL,
	"id_capacities_id"	INTEGER NOT NULL,
	FOREIGN KEY("id_capacities_id") REFERENCES "Capacities"("id_capacities"),
	PRIMARY KEY("id_rooms")
);