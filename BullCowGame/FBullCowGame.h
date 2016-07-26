#pragma once
#include <string>

// Acclimating to Unreal syntax
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
	Invalid_Status
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
	bool AreCharValid(FString) const;

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	FString ConvertToLowerCase(FString) const;

	EGuessStatus CheckGuessValidity(FString) const;
	EReset Reset();
	FBullCowCount SubmitGuess(FString);

private:
	bool bIsWon = false;
	bool IsIsogram(FString) const;

	int32 MyCurrentTry = 1;
	int32 MyMaxTries = 10;

	FString MyHiddenWord;

	void SetMaxTries(int32);
	void SetCurrentTry(int32);
};