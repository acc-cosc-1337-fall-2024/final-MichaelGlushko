#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

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