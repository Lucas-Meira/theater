CREATE TABLE IF NOT EXISTS "Participant" (
	"registration"	INTEGER NOT NULL,
	"first_name"	TEXT NOT NULL,
	"last_name"	TEXT NOT NULL,
	"email"	TEXT NOT NULL,
	"phone_number"	NUMERIC NOT NULL,
	"password"	TEXT NOT NULL,
	"role"	TEXT NOT NULL,
	"play_id_play" INTEGER,
	FOREIGN KEY ("play_id_play") REFERENCES Play("id_play"),
	PRIMARY KEY("registration" AUTOINCREMENT)
);