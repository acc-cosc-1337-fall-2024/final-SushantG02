//
#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll) 
{
    int rolledValue = roll->getRollValue();
    if (rolledValue == point)
    {
        return RollOutcome::point;
    } else if (rolledValue == 7) 
    {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}