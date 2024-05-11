#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Die rolls return values from 1 to 6") 
{
    Die die;  

    for (int i = 0; i < 10; ++i) 
	{
        int result = die.roll();
        REQUIRE(result >= 1);
        REQUIRE(result <= 6);
    }
}

TEST_CASE("Roll values are between 2 and 12") 
{
    Die die1, die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) 
    
    {
        roll.rollDice();
        int result = roll.getRollValue();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}

TEST_CASE("Shooter roll values are between 2 and 12") 
{
    Die die1;
    Die die2;
    Shooter shooter;
    for (int i = 0; i < 10; ++i) 
    {
        Roll* roll = shooter.throw_dice(die1, die2);
        int result = roll->getRollValue();
        
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}
