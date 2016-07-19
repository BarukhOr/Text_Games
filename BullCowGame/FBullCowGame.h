#pragma once
#include <string>

class FBullCowGame {
	public: 
		void Reset(); // Todo make a more rich return value ... perhaps a bool?
		int GetMaxTries();
		int GetCurrentTry();
		bool IsGameWon();
		bool CheckGuessValidity(std::string); // TODO make a more rich return value

	private:
		void SetMaxTries();
		int MyCurrentTry();
		int MyMaxTries();
		bool IsIsogram(std::string);
};