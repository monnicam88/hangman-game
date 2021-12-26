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
short int attempts_count = 5;

const short int LOWER_BOUND = 3;
const short int UPPER_BOUND = 10;
const short int ASCII_CODE_a = 97;
const short int ASCII_CODE_z = 122;

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

	while (true) {
		readUserInput(user_option);

		std::string word_to_be_guessed;
		size_t size = game_dictionary.size();

		if (user_option == "1") {
		}
		else if (user_option == "2") {
		}

		else if (user_option == "3") {
		}

		else if (user_option == "4") {
			exitTheGame();
			break;
		}

		else incorrectUserInput();
	}
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

