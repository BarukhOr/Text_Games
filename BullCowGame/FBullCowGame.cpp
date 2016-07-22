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

	SetMaxTries(MAX_TRIES);
	SetCurrentTry(CURRENT_TRY);
	return;
}

bool FBullCowGame::CheckGuessValidity(FString variable) {
	return false;
}

bool FBullCowGame::IsIsogram(FString) {
	return false;
}