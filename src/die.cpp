//
#include "die.h"

Die::Die() : sides(6), generator(std::random_device{}()) {}

int Die::roll() 
{
    std::uniform_int_distribution<int> distribution(1, sides);
    return distribution(generator);
}