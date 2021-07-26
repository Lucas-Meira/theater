#ifndef RATING_H
#define RATING_H

#include "../basedomain.h"

class Rating : public BaseDomain<std::string>
{
protected:
    bool _isValidRating(std::string rating);
    void _validate(std::string testedValue) override;

    inline static const std::array<const std::string, 6> VALID_VALUES{"general", "10", "12", "14", "16", "18"};

public:
    Rating() {}

    Rating(std::string rating)
    {
        set(rating);
    }
};

#endif