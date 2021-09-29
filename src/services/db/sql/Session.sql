CREATE TABLE IF NOT EXISTS "Sessions" (
    "id_session" VARCHAR(6) NOT NULL,
    "date" TEXT NOT NULL,
    "time" TEXT NOT NULL,
    "play_id" VARCHAR(6),
    "room_id_room" VARCHAR(6),
    FOREIGN KEY ("play_id") REFERENCES Play("id_play"),
    FOREIGN KEY ("room_id_room") REFERENCES Room("id_room"),
    PRIMARY KEY("id_session")
);