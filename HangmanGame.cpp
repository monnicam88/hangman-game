/**
*
* Solution to course project #14
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Monika Mitreva
* @idnumber 62522
* @compiler VC
*
* Cpp file with all the functions
* used in this project
*
*/

#include "HangmanGame.hpp"

std::vector<std::string> game_dictionary;
short int length_of_the_word = 0;
short int attempts_count = 5;		// Initial attempts count

const short int LOWER_BOUND = 3;	// Minimum count of attempts and minimal word length
const short int UPPER_BOUND = 10;	// Maximum count of attempts and maximal word length
const short int ASCII_CODE_a = 97;	// For validation of entered symbols
const short int ASCII_CODE_z = 122;	// to check if they are only lowercase letters

// Create the game dictionary. Push 
// all words from the file in vector
void generateDictionary() {
	std::ifstream file;
	file.open("dictionary.txt", std::ios::in);
	std::string word;

	if (!file.is_open()) {
		std::cerr << "Failed to open the file" << std::endl;
	}
	else {
		while (getline(file, word)) {
			game_dictionary.push_back(word);
		}
	}
	file.close();
}

// Show the game menu
void showGameInterface() {
	std::cout << std::endl;
	std::cout << " ************************** HANGMAN GAME **************************" << std::endl;
	std::cout << std::endl;

	std::cout << "	1. START new game" << std::endl;
	std::cout << "	2. CHOOSE the length of the words you want to play with" << std::endl;
	std::cout << "	3. CHANGE the count of given attempts" << std::endl;
	std::cout << "	4. EXIT the game" << std::endl;

	std::cout << std::endl;
	std::cout << " ******************************************************************" << std::endl;
	std::cout << std::endl;
}

// Read user input from console
void readUserInput(std::string& option) {
	std::cout << "		> Please, select an option: ";
	std::cin >> option;
	std::cout << std::endl;
}

// Main function to play the game
void play() {
	std::string user_option;
	std::vector<std::string> words_with_certain_length;
	short int count_of_guessed_words = 0;

	do {
		readUserInput(user_option);
		
		// Represent the word that have to be guessed like string
		std::string word_to_be_guessed;	
		size_t size = game_dictionary.size();

		if (user_option == "1") {
			// Generate random word if user does not change the length
			if (length_of_the_word == 0) {
				word_to_be_guessed = game_dictionary[rand() % size];
			}

			// Generate the word with the length that user want
			else {
				for (size_t i = 0; i < size; i++) {
					if (length_of_the_word == game_dictionary[i].size()) {
						words_with_certain_length.push_back(game_dictionary[i]);
					}
				}
				word_to_be_guessed = words_with_certain_length[rand() % words_with_certain_length.size()];
			}

			std::vector<bool> already_revealed_letters;
			std::vector<char> already_entered_letters;
			size_t size_word = word_to_be_guessed.size();

			short int used_attempts = 0;
			bool is_word_guessed = false;

			// For every letter push 'false' in the vector of bool variables
			for (auto& character : word_to_be_guessed) {
				already_revealed_letters.push_back(false);
			}

			do {
				std::cout << "	You now have " << (attempts_count - used_attempts) << " attempts." << std::endl;
				std::cout << "	Guess the word:  ";;

				// Traverse the word and check if there is any revealed letters or not
				for (size_t i = 0; i < size_word; i++) {
					if (!already_revealed_letters[i]) {
						std::cout << "_ ";
					}
					else std::cout << word_to_be_guessed[i];
				}

				std::cout << std::endl;
				std::cout << "		> Please, enter a letter: ";

				char current_letter;
				std::cin >> current_letter;
				std::cout << std::endl;

				// Check if the input is letter or another symbol
				if (!validateLetter(current_letter)) {
					std::cout << "  Your input is not correct! Please, enter a valid character to continue." << std::endl;
					std::cout << std::endl;
				}
				else {
					// Check if letter was already entered or not
					if (!isLetterAlreadyEntered(already_entered_letters, current_letter)) {
						bool current_letter_is_in_the_word = false;

						for (size_t i = 0; i < size_word; i++) {
							if (word_to_be_guessed[i] == current_letter) {
								current_letter_is_in_the_word = true;
								already_revealed_letters[i] = true;
							}
						}

						// If inputed letter is not in the word increase the count of used attempts
						if (!current_letter_is_in_the_word) {
							++used_attempts;
						}
						// Check if word is already revealed or not
						else if (isWordRevealed(already_revealed_letters)) {
							is_word_guessed = true;
							break;
						}
						// If current letter is not entered till now, push it back to 
						// vector with another guessed letters
						already_entered_letters.push_back(current_letter);
					}
					else {
						std::cout << "  This letter was already entered. Please, enter a new one to continue! :)" << std::endl;
						std::cout << std::endl;
					}
				}
			} while ((attempts_count - used_attempts) > 0);

			// Clear the vector with words with the length choosen by user
			// to push words with another length if user want
			words_with_certain_length.clear();
			length_of_the_word = 0;

			// If word is revealed show it to the user and 
			// increase the counter of guessed words
			if (!is_word_guessed) {
				std::cout << "	Unfortunately, you did not guess the word " << word_to_be_guessed << std::endl;
				std::cout << "		Wait to be returned to the menu ..." << std::endl;
				waitAndReturnToMenu();
			}
			else {
				std::cout << "	Congratulations! You successfully guessed the word " << word_to_be_guessed << std::endl;
				std::cout << "		Wait to be returned to the menu ..." << std::endl;
				waitAndReturnToMenu();
				++count_of_guessed_words;
			}
		}
		
		else if (user_option == "2") {
			short int new_length = 0;
			readNewLengthOfTheWords(new_length);

			// Check if user input is valid or not
			if (!validateNumber(new_length)) {
				std::cout << std::endl;
				std::cout << "			Incorrect word length!" << std::endl;
				std::cout << std::endl;
			}
			else changeTheWordsLength(new_length);
		}
		
		else if (user_option == "3") {
			short int new_attempts_count = 0;
			readTheNewAttemptsCount(new_attempts_count);
			
			// TO DO: Fix this validation to work with characters 
			// because inputed character cause an infinite loop
			// Check if user input is valid or not
			if (!validateNumber(new_attempts_count)) {
				std::cout << std::endl;
				std::cout << "			Incorrect attempts count!" << std::endl;
				std::cout << std::endl;
			}
			else changeTheCountOfGivenAttempts(new_attempts_count);
		}

		else if (user_option == "4") {
			exitTheGame();
			break;
		}

		else incorrectUserInput();
	} while (true);
	
	// Show the user how many words he managed to reveal
	std::cout << std::endl;
	std::cout << "				  The words you manage to guess are: " << count_of_guessed_words << std::endl;
}

// Change the length of the words
void changeTheWordsLength(const short int& new_word_length) {
	length_of_the_word = new_word_length;
	std::cout << std::endl;
	std::cout << "   You successfully change the length of the words you will play with to: " << new_word_length << std::endl;
	std::cout << std::endl;
}

// Change the count of giving attempts 
void changeTheCountOfGivenAttempts(const short int& new_attempts) {
	attempts_count = new_attempts;
	std::cout << std::endl;
	std::cout << "  You successfully change the count of attempts you will play with to: " << new_attempts << std::endl;
	std::cout << std::endl;
}

// The user select the new length of the words
void readNewLengthOfTheWords(short int& new_length) {
	std::cout << "  When the game starts, a random word is generated with any number of letters." << std::endl;
	std::cout << "  You can change this by choosing the length of the words you want to play with." << std::endl;
	std::cout << "  The minimum length of a word is 3 letters and the maximum length is 10 letters." << std::endl;
	std::cout << "  Please, enter the length of the words you will start the game with: ";

	std::cin >> new_length;
}

// The user select the count of new attempts
void readTheNewAttemptsCount(short int& new_attempts_count) {
	std::cout << "  At the start of the game, each player has 5 attempts to guess a specific word." << std::endl;
	std::cout << "	  You can change the number of given attempts if you want." << std::endl;
	std::cout << "	     Their count should be a number between 3 and 10." << std::endl;
	std::cout << "  Please, enter the count of new attempts you will start the game with: ";

	std::cin >> new_attempts_count;
}

// Show message for incorrect user input
void incorrectUserInput() {
	std::cout << "  Your input is not correct. Please, enter a valid option to start the game! :)" << std::endl;
	std::cout << "	REMINDER: A valid option is a number between 1 and 4!" << std::endl;
	std::cout << std::endl;
}

// Exit the game
void exitTheGame() {
	cleanScreen();
	std::cout << std::endl;
	std::cout << "				  Thank you for your participation! :)" << std::endl;
	std::cout << "		To exit the game, press any key to close the window, please. Have a nice day!" << std::endl;
}

// Clean the console window
void cleanScreen() {
	#ifdef _WIN32
		system("cls");
	#elif __linux __
		system("clear");
	#else 
		for (int i = 0; i <= 1000; i++) {
			std::cout << std::endl;
		}
	#endif
}

void waitAndReturnToMenu() {
	Sleep(4000);
	cleanScreen();
	showGameInterface();
}

// Checking if the letter entered by user is already entered before
bool isLetterAlreadyEntered(const std::vector<char>& letters, const char& letter) {
	for (auto& symbol : letters) {
		if (symbol == letter) {
			return true;
		}
	}
	return false;
}

// Checking if all letters from the words are guessed
// (if all bool variables are 'true')
bool isWordRevealed(const std::vector<bool>& guessed_letters) {
	for (auto element : guessed_letters) {
		if (element == false) {
			return false;
		}
	}
	return true;
}

// Validate letters to be only uppercase nad lowercase
bool validateLetter(const char& letter) {
	if (letter >= ASCII_CODE_a && letter <= ASCII_CODE_z) {
		return true;
	}
	return false;
}

// Validate the word length and the count of attempts entered by user
bool validateNumber(const short int& number) {
	if (number >= LOWER_BOUND && number <= UPPER_BOUND) {
		return true;
	}
	return false;
}
