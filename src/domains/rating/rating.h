#ifndef RATING_H
#define RATING_H

#include "../basedomain.h"

///
/// This class inherits from BaseDomain with public access mode.
///
/// Representation of the age rating of the play.
///
/// Format rules:
/// - The value will be one of the following types: "general", "10", "12", "14", "16", "18"
///

class Rating : public BaseDomain<std::string>
{
protected:
    ///
    /// Returns true if the value is an allowed age rating of the play, and returns false otherwise.
    ///
    /// @param rating
    ///

    bool _isValidRating(const std::string &rating);

    /// Checks the validity of the given input.
    /// @throw invalid_argument
    /// @param testedValue
    ///

    void _validate(const std::string &testedValue) override;

    inline static const std::array<const std::string, 6> VALID_VALUES{"general", "10", "12", "14", "16", "18"};

public:
    ///
    /// Creates an instance of the class Rating.
    ///

    Rating() {}

    ///
    /// Initializes the object with a rating if its value is valid.
    ///
    /// @param rating
    ///

    Rating(const std::string &rating)
    {
        set(rating);
    }
};

#endif
