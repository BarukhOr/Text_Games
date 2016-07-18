#include <iostream>
#include <string>

using namespace std;

// Global variable declarations
constexpr int WORD_LENGTH = 5;

// Function declarations
void PrintIntro();
string GetGuess();
void PlayGame();
bool AskToPlayAgain();

// The Entry point for this application
int main() {
	PrintIntro();
	PlayGame();
	AskToPlayAgain();
	return 0;	// Exit the application
}

// Introduce the game
void PrintIntro() {
	cout << "Greetings and Welcome to Bulls and Cows." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I am thinking of?" << endl;
}

// Get a guess from the player
string GetGuess() {
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	cout << endl;
	return Guess;
}

void PlayGame() {
	do {
		constexpr int NUMBER_OF_TURNS = 1;
		// Loop for the number of turns asking for guesses
		for (int counter = 0; counter < NUMBER_OF_TURNS; counter++) {
			string Guess = GetGuess();
			cout << "The inputted word was: " << Guess << endl;
		}
	} while(AskToPlayAgain());
}

bool AskToPlayAgain() {
	cout << "Do you want to play again?" << endl << "Press y for yes or n for no." << endl;
	string Response = "";
	getline(cin, Response);

	cout << "Is it y? " << (Response[0] == 'y') << endl;
	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else if (Response[0] == 'n' || Response[0] == 'N') {
		return false;
	}

	return false;
}