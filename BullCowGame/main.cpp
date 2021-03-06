/*
* This is the console executable. It makes use of the BullCow Class and makes use of the MVC pattern.
* It is responsible for user interaction. For game logic see the BullCow class.
*/

#include <iostream>
#include "FBullCowGame.h"

//Instantiate a new game
FBullCowGame BCGame;

// Function declarations
bool AskToPlayAgain();
FString GetValidGuess();
void PlayGame();
void PrintGameSummary();
void PrintIntro();

// The Entry point for this application
int main() {
	PrintIntro();
	do{
		PlayGame();
	}while(AskToPlayAgain());
		
	return 0;	// Exit the application
}

// Introduce the game
void PrintIntro() {
	std::cout << "Greetings and Welcome to Bulls and Cows." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram that I am thinking of?" << std::endl;
}

// Loop continuously until the user inputs a valid guess
FString GetValidGuess() {
	FString Guess = "";
	EGuessStatus GuessStatus = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);
		std::cout << std::endl;

		GuessStatus = BCGame.CheckGuessValidity(Guess);
		switch (GuessStatus) {
		case EGuessStatus::Invalid_Characters:
			std::cout << "Your previous string contained invalid characters. Please enter a valid string." << std::endl;
			break;
		case EGuessStatus::Invalid_Word_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word with non-recurring letters" << std::endl;
			break;
		default:
			// this implies that there were no detected errors within the Guess
			break;
		}
	} while (GuessStatus != EGuessStatus::OK); // Continue looping until there are no input errors
	return Guess;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "You have a maximum of " << MaxTries << " tries available" << std::endl;

	/*
	 * Loop asking for guesses while the game is not won
	 * and there are still tries remaining
	 */
	 while( !BCGame.IsGameWon()  && BCGame.GetCurrentTry() <= MaxTries){
		FString Guess = GetValidGuess();
		Guess = BCGame.ConvertToLowerCase(Guess);
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;
	 }
	 
	 PrintGameSummary();
	 return;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word?" << std::endl << "Press y for yes or n for no. \n";
	FString Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary(){
	// Provide victory or defeat message
	if(BCGame.IsGameWon()){
		std::cout << "Congratulations! You win! " << std::endl;
	}else{
		std::cout << "Better luck next time~ " << std::endl;
	}
}