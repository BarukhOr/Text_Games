#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // Todo make a more rich return value ... perhaps a bool?
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	bool IsIsogram(FString);
	// Create a function that will count bulls and cows,
	// Create a function that will increment the current try

private:
	void SetMaxTries(int32);
	void SetCurrentTry(int32);
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
};