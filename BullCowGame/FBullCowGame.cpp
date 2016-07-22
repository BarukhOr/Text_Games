#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

// Getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

// Setters
void FBullCowGame::SetMaxTries(int32 number) { MyMaxTries = number; }
void FBullCowGame::SetCurrentTry(int32 number) { MyCurrentTry = number; }

void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 2;
	constexpr int CURRENT_TRY = 1;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	SetMaxTries(MAX_TRIES);
	SetCurrentTry(CURRENT_TRY);
	return;
}

bool FBullCowGame::CheckGuessValidity(FString variable) {
	return false;
}

bool FBullCowGame::IsIsogram(FString word) {
	return false;
}

// receives a VALID guess and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	// increment the turn number
	IncrementCurrentTry();

	// setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	// loop through all letters in the guess and compare the guess against the hidden word
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// if the letters are in the same place
		if (Guess[i] == MyHiddenWord[i]) {
			// increment bulls 
			BullCowCount.Bulls++;
		}
		else {
			// must be a cow
			BullCowCount.Cows++;
		}
	}

	return BullCowCount;
}

void FBullCowGame::IncrementCurrentTry() {
	SetCurrentTry(MyCurrentTry++);
	return;
}