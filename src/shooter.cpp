#include "shooter.h"
#include <iostream>



Roll* Shooter::throw_dice(Die& die1, Die& die2) 
{
    Roll* new_roll = new Roll(die1, die2);
    new_roll->rollDice();
    rolls.push_back(new_roll);
    return new_roll;
}
void Shooter::display_rolled_values() 
{
    for (Roll* roll : rolls) {
        std::cout << "Rolled value: " << roll->getRollValue() << std::endl;
    }
}
Shooter::~Shooter() 
{
    for (Roll* roll : rolls) {
        delete roll;
    }
}