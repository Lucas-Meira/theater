CREATE TABLE IF NOT EXISTS "Plays" (
	"id_plays"	TEXT NOT NULL,
	"name"	TEXT NOT NULL,
	"id_classification_id"	TEXT NOT NULL,
	"id_playtypes_id"	INTEGER NOT NULL,
	FOREIGN KEY("id_classification_id") REFERENCES "Classidications"("id_classification"),
	FOREIGN KEY("id_playtypes_id") REFERENCES "PlayTypes"("id_playtypes"),
	PRIMARY KEY("id_plays")
);