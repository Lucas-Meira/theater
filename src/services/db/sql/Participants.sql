CREATE TABLE IF NOT EXISTS "Participants" (
	"registrations"	INTEGER NOT NULL,
	"first_name"	TEXT NOT NULL,
	"last_name"	TEXT NOT NULL,
	"email"	TEXT NOT NULL,
	"phoe_number"	NUMERIC NOT NULL,
	"password"	TEXT NOT NULL,
	"id_roletypes_id"	INTEGER NOT NULL,
	"id_plays_id"	TEXT NOT NULL,
	FOREIGN KEY("id_plays_id") REFERENCES "Plays"("id_plays"),
	FOREIGN KEY("id_roletypes_id") REFERENCES "RoleTypes"("id_roletypes"),
	PRIMARY KEY("registrations")
);