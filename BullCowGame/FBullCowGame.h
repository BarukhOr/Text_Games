#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all variables set to 0 on intialization
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Invalid_Word_Length,
	Invalid_Characters,
	Invalid_Status,
	Not_Lowercase	// TODO convert user input to lowercase using tolower()
};

enum class EReset {
	OK,
	No_Hidden_Word,
	Invalid_Status
};

class FBullCowGame {
public:
	FBullCowGame(); // constructor

	bool IsGameWon() const;
	bool IsLengthValid(FString) const;

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	FString ConvertToLowerCase(FString) const;

	EGuessStatus CheckGuessValidity(FString) const; // TODO make a more rich return value
	EReset Reset(); // Todo make a more rich return value ... perhaps a bool?

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