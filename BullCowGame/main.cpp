/*
* This is the console executable. It makes use of the BullCow Class and makes use of the MVC pattern.
* It is responsible for user interaction. For game logic see the BullCow class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Acclimating to Unreal syntax, wherein FText is oft used for user interaction
using FText = std::string;
// Unreal's suggested implementation of int
using int32 = int;

// Global variable declarations
constexpr int32 WORD_LENGTH = 5;

//Instantiate a new game
FBullCowGame BCGame;

// Function declarations
void PrintIntro();
FText GetGuess();
void PlayGame();
bool AskToPlayAgain();

// The Entry point for this application
int main() {
	PrintIntro();
	PlayGame();
	return 0;	// Exit the application
}

// Introduce the game
void PrintIntro() {
	std::cout << "Greetings and Welcome to Bulls and Cows." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I am thinking of?" << std::endl;
}

// Get a guess from the player
FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "You have a maximum of " << MaxTries << " tries available" << std::endl;

	bool bPlayAgain = false;

	do {
		// Loop for the number of turns asking for guesses
		//TODO change from FOR to WHILE once we begin validating tries
		for (int32 counter = 0; counter < MaxTries; counter++) {
			FText Guess = GetGuess();
			// TODO check for valid guesses
			// TODO submit valid guesses to the game
			// TODO print number of bulls and cows
			std::cout << "The inputted word was: " << Guess << std::endl;
		}
		// TODO add a game summary
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? \n" << std::endl << "Press y for yes or n for no. \n";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}