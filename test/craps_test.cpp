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

TEST_CASE("Test that shooter returns a roll and verify that the roll result is between 2-12") {
	Die die1;
	Die die2;
	Shooter shooter;
	for(int i = 1; i <= 10; i++) {
		Roll* roll = shooter.throw_dice(die1, die2);
		int value = roll->roll_value();
		REQUIRE((value >= 2 && value <= 12));
	}
}

TEST_CASE("Test that ComeOutPhase get outcomes returns values RollOutcome::natural, RollOutcome::craps, and RollOutcome::point") {
	Die die1;
	Die die2;
	ComeOutPhase cop;

	for(int i = 1; i <= 10; i++) {
		Roll roll(die1, die2);
		RollOutcome outcome = cop.get_outcome(&roll);
		REQUIRE((outcome == RollOutcome::natural || outcome == RollOutcome::craps || outcome == RollOutcome::point));
	}
}

TEST_CASE("Test that PointPhase get outcomes returns values RollOutcome::point, RollOutcome::seven_out, and RollOutcome::nopoint") {
	Die die1;
	Die die2;
	PointPhase pPhase(5);
	
	for(int i = 1; i <= 10; i++) {
		Roll roll(die1, die2);
		RollOutcome outcome = pPhase.get_outcome(&roll);
		REQUIRE((outcome == RollOutcome::point || outcome == RollOutcome::seven_out || outcome == RollOutcome::nopoint));
	}
}