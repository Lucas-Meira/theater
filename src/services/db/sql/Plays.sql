CREATE TABLE IF NOT EXISTS "Plays" (
    "id_play" VARCHAR(6) NOT NULL,
    "name" TEXT NOT NULL,
    "classification" TEXT NOT NULL,
    "type_id_type" INTEGER,
    FOREIGN KEY ("type_id_type") REFERENCES Type("id_type"),
    PRIMARY KEY("id_play")
);
