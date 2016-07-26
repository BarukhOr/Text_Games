#include "FBullCowGame.h"
#include <iostream>
#include <map>
#include <locale>

#define TMap std::map

FBullCowGame::FBullCowGame(){
	Reset();
}

// Getters
bool FBullCowGame::IsGameWon() const { return bIsWon; }
bool FBullCowGame::IsIsogram(FString Word) const{
	// Treat zero or one letter words as isograms
	if(Word.length() <= 1) { return true; }
	// Setup the map
	TMap<char, bool> LetterSeen;
	
	// Loop through the provided word
	for(auto Letter : Word){	// for all characters in the word
		// Check each character into the map
		if(LetterSeen[Letter]){ // If a letter is already in the map, return false (in other words, the provided word is not an isogram)
			return false;
		}else{ // If the letter is not in the map, add the letter to the map
			LetterSeen[Letter] = true;
		}
	}

	return true; // this also covers strange cases e.g. where /0 is entered
}
bool FBullCowGame::IsLengthValid(FString Guess) const {
	int32 GuessLength = Guess.length();
	if(GuessLength == GetHiddenWordLength()){
		return true;
	}else{
		return false;
	}
	return false;
}
bool FBullCowGame::AreCharValid(FString Guess) const {
	std::locale loc;
	for(auto Letter : Guess){
		if(!std::isalpha(Letter,loc)){
			return false;
		}
	}
	return true;
}
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FString FBullCowGame::ConvertToLowerCase(FString Guess) const{	// TODO make this function more locale friendly
	for(char& SingleChar : Guess) {
		SingleChar = tolower(SingleChar);
	}
	return Guess;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	if(!IsIsogram(Guess)){ // TODOO: if the guess is not an isogram
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLengthValid(Guess)){ // if the length of the word is invalid ()
		return EGuessStatus::Invalid_Word_Length;
	}
	else if (!AreCharValid(Guess)){ // TODO: if the guess contains invalid characters
		return EGuessStatus::Invalid_Characters;
	}else{
		return EGuessStatus::OK;
	}
}

EReset FBullCowGame::Reset(){
	constexpr int MAX_TRIES = 5;
	constexpr int CURRENT_TRY = 1;
	
	const FString HIDDEN_WORD = "planet";
	
	MyHiddenWord = HIDDEN_WORD;
	bIsWon = false;
	
	SetMaxTries(MAX_TRIES);
	SetCurrentTry(CURRENT_TRY);
	
	if (HIDDEN_WORD=="" || HIDDEN_WORD.empty()){
		return EReset::No_Hidden_Word;
	}
	return EReset::OK; 
}

// Setters
void FBullCowGame::SetMaxTries(int32 number) { MyMaxTries = number; }
void FBullCowGame::SetCurrentTry(int32 number) { MyCurrentTry = number; }



// receives a VALID guess and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
	// increment the turn number
	SetCurrentTry(MyCurrentTry + 1);
	
	// setup a return variable
	FBullCowCount BullCowCount;
	
	int32 HiddenWordLength = MyHiddenWord.length();
	
	/*
	 * Assuming that both the hidden word and the guess word are of equal length.
	 * Loop through all letters in the guess and compare the guess against the hidden word.
	 */
	for(int32 i = 0; i < HiddenWordLength; i++){
		// if the letters are in the same place
		if(Guess[i] == MyHiddenWord[i]){
			// increment bulls 
			BullCowCount.Bulls++;
		}else{
			// must be a cow
			BullCowCount.Cows++;
		}
	}
	
	if(BullCowCount.Bulls == HiddenWordLength){
		bIsWon = true;
		std::cout << "Congratulations you have correctly guessed the word." << std::endl;
	}else{
		bIsWon = false;
	}
		
	return BullCowCount;
}