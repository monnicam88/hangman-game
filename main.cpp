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
* Main cpp file
*
*/

#include "HangmanGame.hpp"

int main() {
	generateDictionary();
	showGameInterface();
	play();	// Function with all the logic for the game

	return 0;
}