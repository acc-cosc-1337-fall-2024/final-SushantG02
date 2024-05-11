//
#include "roll.h"

Roll::Roll(Die& die1_ref, Die& die2_ref) : die1(die1_ref), die2(die2_ref), rolledValue(0) {}

void Roll::rollDice() 
{
    rolledValue = die1.roll() + die2.roll();
}

int Roll::getRollValue() const
{
    return rolledValue;
}
void Roll::setRollValue(int value) 
{
    rolledValue = value;
}