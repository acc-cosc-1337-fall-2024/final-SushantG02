//
#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) 
{
    int rolledValue = roll->getRollValue();
    if (rolledValue == 7 || rolledValue == 11)
    {
        return RollOutcome::natural;
    } else if (rolledValue == 2 || rolledValue == 3 || rolledValue == 12) 
    {
        return RollOutcome::craps;
    } else {
        return RollOutcome::point;
    }
}