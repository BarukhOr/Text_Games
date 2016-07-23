#include "FBullCowGame.h"
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

// Getters
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::IsLengthValid(FString Guess) const {
	if (Guess.length() != GetHiddenWordLength()) {
		return false;
	}
	else {
		return true;
	}
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FString FBullCowGame::ConvertToLowerCase(FString Guess) const {	// TODO make this function more locale friendly
	for (char& SingleChar : Guess) {
		SingleChar = tolower(SingleChar);
	}
	return Guess;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if (false) { // if the guess is not an isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (IsLengthValid(Guess)) { // if the length of the word is invalid ()
		return EGuessStatus::Invalid_Word_Length;
	}
	else if (false) { // if the guess contains invalid characters
		return EGuessStatus::Invalid_Characters;
	}
	else {
		return EGuessStatus::OK;
	}
}

EReset FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 2;
	constexpr int CURRENT_TRY = 1;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	SetMaxTries(MAX_TRIES);
	SetCurrentTry(CURRENT_TRY);
	return EReset::OK;
}

// Setters
void FBullCowGame::SetMaxTries(int32 number) { MyMaxTries = number; }
void FBullCowGame::SetCurrentTry(int32 number) { MyCurrentTry = number; }



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