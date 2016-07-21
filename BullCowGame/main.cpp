#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Global variable declarations
constexpr int WORD_LENGTH = 5;

//Instantiate a new game
FBullCowGame BCGame;

// Function declarations
void PrintIntro();
std::string GetGuess();
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
std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "You have a maximum of " << MaxTries << " tries available" << std::endl;

	bool bPlayAgain = false;

	do {
		// Loop for the number of turns asking for guesses
		for (int counter = 0; counter < MaxTries; counter++) {
			std::string Guess = GetGuess();
			std::cout << "The inputted word was: " << Guess << std::endl;
		}
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again? \n" << std::endl << "Press y for yes or n for no. \n";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}