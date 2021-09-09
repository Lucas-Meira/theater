CREATE TABLE IF NOT EXISTS "Sessions" (
	"id_sessaion"	INTEGER NOT NULL,
	"date"	TEXT NOT NULL,
	"time"	TEXT NOT NULL,
	"play_id" INTEGER,
	"room_id_room" INTEGER,
	FOREIGN KEY ("play_id") REFERENCES Play("id_play"),
	FOREIGN KEY ("room_id_room") REFERENCES Room("id_room"),
	PRIMARY KEY("id_sessaion" AUTOINCREMENT)
);