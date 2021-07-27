#ifndef STATE_H
#define STATE_H

#include <cstdint>

class State
{
private:
    int8_t _state;

public:
    inline const static int8_t SUCCESS = 0;
    inline const static int8_t FAILURE = -1;

    int8_t get()
    {
        return _state;
    }

    void set(bool state)
    {
        if (_state == FAILURE)
        {
            return;
        }

        if (state)
        {
            _state = SUCCESS;
        }
        else
        {
            _state = FAILURE;
        }
        }
};

#endif