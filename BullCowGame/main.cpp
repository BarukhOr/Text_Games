#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Global variable declarations
constexpr int WORD_LENGTH = 5;

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
	std::string Guess = "";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

void PlayGame() {
	FBullCowGame BCGame;
	bool bPlayAgain = false;

	do {
		constexpr int NUMBER_OF_TURNS = 1;
		// Loop for the number of turns asking for guesses
		for (int counter = 0; counter < NUMBER_OF_TURNS; counter++) {
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