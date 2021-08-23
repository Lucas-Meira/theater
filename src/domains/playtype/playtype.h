#ifndef PLAY_TYPE_H
#define PLAY_TYPE_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of the type of the play in the theater.
///
/// Format rules:
/// - The value will be one of the following types: "Auto", "Comedy", "Drama", "Farce", "Melodrama", "Monologue", "Musical", "Opera", "Revue"
///

class PlayType : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if the value is an allowed type of play, and returns false otherwise.
    ///
    /// @param type
    ///

    bool _isValidType(std::string type);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(std::string testedValue) override;

public:
    ///
    /// Creates an instance of the class PlayType.
    ///

    PlayType() {}

    ///
    /// Initializes the object with a type if its value is valid.
    ///
    /// @param type
    ///

    PlayType(std::string type)
    {
        set(type);
    }

    inline static const std::array<std::string, 9> VALID_VALUES{"Auto", "Comedy", "Drama", "Farce", "Melodrama",
                                                                "Monologue", "Musical", "Opera", "Revue"};
};

#endif
