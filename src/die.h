#ifndef DIE_H
#define DIE_H

#include <random>

class Die 
{
public:
    Die();
    int roll();

private:
    int sides;
    std::default_random_engine generator;
};

#endif