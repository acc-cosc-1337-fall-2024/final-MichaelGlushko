//
#include "roll.h"

void Roll::roll_dice() {
    rolled_value = die1.roll() + die2.roll();
}

int Roll::roll_value() const {
    return rolled_value;
}