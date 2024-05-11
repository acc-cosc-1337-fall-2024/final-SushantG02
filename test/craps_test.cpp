#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"


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


TEST_CASE("ComeOutPhase returns correct outcomes for rolled values")
 {
    Die die1;
    Die die2;
    ComeOutPhase comeOutPhase;

    SECTION("Rolled value is 7 or 11") 
    {
        Roll roll(die1, die2);
        roll.setRollValue(7); 
        REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::natural);
    }

    SECTION("Rolled value is 2, 3, or 12") 
    {
        Roll roll(die1, die2);
        roll.setRollValue(2); 
        REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::craps);
    }

    SECTION("Rolled value is not 7, 11, 2, 3, or 12") 
    {
        Roll roll(die1, die2);
        roll.setRollValue(5); 
        REQUIRE(comeOutPhase.get_outcome(&roll) == RollOutcome::point);
    }
}

TEST_CASE("PointPhase returns correct outcomes for rolled values")
 {
    Die die1;
    Die die2;
    PointPhase pointPhase(5); 

    SECTION("Rolled value is equal to point")
     {
        Roll roll(die1, die2);
        roll.setRollValue(5); 
        REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::point);
    }

    SECTION("Rolled value is 7") 
    {
        Roll roll(die1, die2);
        roll.setRollValue(7); 
        REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::seven_out);
    }

    SECTION("Rolled value is not point or 7") 
    {
        Roll roll(die1, die2);
        roll.setRollValue(4); 
        REQUIRE(pointPhase.get_outcome(&roll) == RollOutcome::nopoint);
    }
}