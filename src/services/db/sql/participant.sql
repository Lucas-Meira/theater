CREATE TABLE IF NOT EXISTS Participants (
    registration VARCHAR(5) NOT NULL PRIMARY KEY,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(20) NOT NULL,
    email VARCHAR(330) NOT NULL,
    phone_number VARCHAR(20) NOT NULL,
    password VARCHAR(8) NOT NULL,
    role VARCHAR(20) NOT NULL
    );