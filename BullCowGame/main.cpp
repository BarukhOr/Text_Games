#include <iostream>
#include <string>

using namespace std;

// Global variable declarations
constexpr int WORD_LENGTH = 5;

// Function declarations
void PrintIntro();
string GetGuess();
void PlayGame();

// The Entry point for this application
int main() {
	
	PrintIntro();
	PlayGame();
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
	constexpr int NUMBER_OF_TURNS = 5;
	// Loop for the number of turns asking for guesses
	for (int counter = 0; counter < NUMBER_OF_TURNS; counter++) {
		string Guess = GetGuess();
		cout << "The inputted word was: " << Guess << endl;
	}
}