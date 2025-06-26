## Hangman Game
[![C++14](https://img.shields.io/badge/C%2B%2B-14-orange)](https://en.cppreference.com/w/cpp/14) [![License: MIT](https://img.shields.io/badge/License-MIT-darkpurple.svg)](https://opensource.org/licenses/MIT)
   
_This game is a simple implementation of the classic word-guessing game, Hangman. It is implemented in C++ with the use of vectors and strings from the standard library (as to avoid any manual memory management issues). More info about the game can be found here: https://en.wikipedia.org/wiki/Hangman_(game)_

### SHORT INSTRUCTIONS
When entering a symbol or number other than the numbers _**1, 2, 3**_ or _**4**_, the user cannot start the game. When changing the **length of the words** or **the number of attempts allowed**, if the user input is **invalid**, the player is required to **re-select one of the original options _**1, 2, 3**_ or _**4**_** and then start the game.

### Interface
---
**To implement a version of the game Hangman by using a pre-generated or personal generated dictionary of words (optional). 
When the game starts, the following menu is provided to the user:**
   
        1. Start a new game
        2. Settings
            a). Change the length of the word for the game
            b). Change the number of attempts
        3. Exit 
     
### Functionalities
  ---
        1. START A NEW GAME
    
- The program selects a random word from the dictionary. 
- The word is displayed as the unguessed letters are replaced by _.
- The user enters a letter. 
- When you enter an invalid letter (not a Latin alphabet symbol), an error message is displayed.
- When entering a valid letter:
    - If the letter is part of the word, the places where it occurs are written.
    - If the letter is not part of the word, reduce the number of attempts by 1.
 - When you enter a letter that was entered earlier, the number of attempts is not reduced.
 - Until the number of attempts is complete or the user does not recognize the word, user entered a letters.
 - At the end of the game (exhaustion of the number of attempts), it is written whether the player has known the word or      not and what the word is. Then it returns to the main menu.

        2. SETTINGS

**The settings can change the behavior of the game. Decide for yourself how the game settings will change.
There are 2 possible changes:**
- Change the length of the word. By default, the length of the word is not limited. The player can choose to select words   between 5 and 7 letters, for example.
- Change the number of attempts. By default, the player is entitled to 5 attempts. This number can be changed, for example,   to 3 attempts.

        3. EXIT

**When this option is selected, the game is exited and the program closes.**
