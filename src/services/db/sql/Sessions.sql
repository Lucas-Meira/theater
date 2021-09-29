CREATE TABLE IF NOT EXISTS "Sessions" (
	"id_sessions"	TEXT NOT NULL,
	"date"	TEXT NOT NULL,
	"time"	TEXT NOT NULL,
	"id_plays_id"	TEXT NOT NULL,
	"id_rooms_id"	TEXT NOT NULL,
	FOREIGN KEY("id_plays_id") REFERENCES "Plays"("id_plays"),
	FOREIGN KEY("id_rooms_id") REFERENCES "Rooms"("id_rooms"),
	PRIMARY KEY("id_sessions")
);