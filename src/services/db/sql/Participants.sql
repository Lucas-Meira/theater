CREATE TABLE  IF NOT EXISTS "Participants" (
	"registration"	INTEGER NOT NULL,
	"first_name"	TEXT NOT NULL,
	"last_name"	TEXT NOT NULL,
	"email"	TEXT NOT NULL,
	"phone_number"	TEXT NOT NULL,
	"password"	TEXT NOT NULL,
	"role"	TEXT NOT NULL,
	"id_plays_id"	TEXT,
	FOREIGN KEY("id_plays_id") REFERENCES "Plays"("id_plays"),
	PRIMARY KEY("registration")
);