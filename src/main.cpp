#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "die.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

using std:: cout; 


int main() {
    srand(time(0)); 

    Die die1;
    Die die2;
    Shooter shooter;

    Roll* roll = shooter.throw_dice(die1, die2);

    int rolled_value = roll->getRollValue();

    ComeOutPhase come_out_phase;
    while (come_out_phase.get_outcome(roll) == RollOutcome::natural ||
           come_out_phase.get_outcome(roll) == RollOutcome::craps) {
           cout << "Rolled " << rolled_value << ". Roll again.\n";
        delete roll; 
        roll = shooter.throw_dice(die1, die2);
        rolled_value = roll->getRollValue();
    }

    std::cout << "Start of point phase\n";
    std::cout << "Roll until " << rolled_value << " or a 7 is rolled.\n";

    int point = rolled_value;
    delete roll; 
    roll = shooter.throw_dice(die1, die2);
    PointPhase point_phase(point);

    while (point_phase.get_outcome(roll) != RollOutcome::seven_out &&
           point_phase.get_outcome(roll) != RollOutcome::nopoint) {
           cout << "Rolled " << roll->getRollValue() << ". Roll again.\n";
        delete roll;
        roll = shooter.throw_dice(die1, die2);
    }

    cout << "End of point phase\n";
    cout << "Shooter rolled values:\n";
    cout << point << '\n'; 
    cout << roll->getRollValue() << '\n';

    delete roll; 

    return 0;
}

// using #include <cstdlib> for randmon number generation, I was getting errors when I used std::srand(std::time(nullptr)); for random number generation. 