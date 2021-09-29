CREATE TABLE IF NOT EXISTS "Participants" (
    "registration" INTEGER NOT NULL,
    "first_name" TEXT NOT NULL,
    "last_name" TEXT NOT NULL,
    "email" TEXT NOT NULL,
    "phone_number" NUMERIC NOT NULL,
    "password" TEXT NOT NULL,
    "role" TEXT NOT NULL,
    "id_plays_id" VARCHAR(6),
    FOREIGN KEY ("id_plays_id") REFERENCES Play("id_plays"),
    PRIMARY KEY("registration" )
);