#include <iostream>
#include <string>

using namespace std;

int main() {
	constexpr int WORD_LENGTH = 5;
	
	//Introduce the game
	cout << "Greetings and Welcome to Bulls and Cows." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram that I am thinking of?" << endl;

	// Get a guess from the player
	string Guess = "";
	cout << "Enter your guess: ";
	cin >> Guess;
	cout << endl;

	// Repeat the guess back to the user
	cout << "The inputted word was: " << Guess << endl;
	return 0;
}