#ifndef PLAY_TYPE_H
#define PLAY_TYPE_H

#include "../basedomain.h"

class PlayType : public BaseDomain<std::string>
{
protected:
    bool _isValidType(std::string type);
    void _validate(std::string testedValue) override;

public:
    PlayType() {}

    PlayType(std::string type)
    {
        set(type);
    }

    inline static const std::array<std::string, 9> VALID_VALUES{"Auto", "Comedy", "Drama", "Farce", "Melodrama",
                                                                "Monologue", "Musical", "Opera", "Revue"};
};

#endif