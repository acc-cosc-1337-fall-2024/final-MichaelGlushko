#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify die rolls returns a value from 1 to 6") {
	Die turn;
	
	for(int i = 1; i <= 10; i++) {
		int value = turn.roll();
		REQUIRE((value >= 1 && value <= 6));
	}
}

TEST_CASE("Verify that die rolls return a value from 2 to 12") {
	Die die1;
	Die die2;
	Roll turn(die1, die2);
	
	for(int i = 1; i <= 10; i++) {
		turn.roll_dice();
		int value = turn.roll_value();
		REQUIRE((value >= 2 && value <= 12));
	}
}