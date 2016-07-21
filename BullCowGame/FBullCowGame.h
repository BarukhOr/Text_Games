#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // Todo make a more rich return value ... perhaps a bool?
	bool CheckGuessValidity(std::string); // TODO make a more rich return value
	bool IsIsogram(std::string);
	// Create a function that will count bulls and cows,
	// Create a function that will increment the current try

private:
	void SetMaxTries(int);
	void SetCurrentTry(int);
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};