#include <iostream>
#include <string>

using namespace std;

// Global variable declarations
constexpr int WORD_LENGTH = 5;

// Function declarations
void PrintIntro();
string GetGuess();

// The Entry point for this application
int main() {
	
	PrintIntro();
	string Guess = GetGuess();
	// Repeat the guess back to the user
	cout << "The inputted word was: " << Guess << endl;

	Guess = GetGuess();
	// Repeat the guess back to the user
	cout << "The inputted word was: " << Guess << endl;
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