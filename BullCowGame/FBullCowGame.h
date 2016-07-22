#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all variables set to 0 on intialization
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // Todo make a more rich return value ... perhaps a bool?
	bool CheckGuessValidity(FString); // TODO make a more rich return value
	bool IsIsogram(FString);
	// Create a function that will count bulls and cows
	FBullCowCount SubmitGuess(FString);
	// Create a function that will increment the current try assuming valid guess
	void IncrementCurrentTry();

private:
	void SetMaxTries(int32);
	void SetCurrentTry(int32);
	FString MyHiddenWord;
	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 5;
};