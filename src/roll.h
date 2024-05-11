//
#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Roll {
public:
    Roll(Die& die1, Die& die2);
    void rollDice();
    int getRollValue() const;

private:
    Die& die1;
    Die& die2;
    int rolledValue;
};

#endif 