#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

// Getters
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

// Setters
void FBullCowGame::SetMaxTries(int number) { MyMaxTries = number; }
void FBullCowGame::SetCurrentTry(int number) { MyCurrentTry = number; }

void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 2;
	constexpr int CURRENT_TRY = 1;

	SetMaxTries(MAX_TRIES);
	SetCurrentTry(CURRENT_TRY);
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string variable) {
	return false;
}

bool FBullCowGame::IsIsogram(std::string) {
	return false;
}