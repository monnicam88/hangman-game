## Hangman Game
                        Project for the course Introduction to programming - FMI 2021/2022
   
_This game is a simple implementation of the classic word-guessing game, Hangman. It is implemented in C++ with the use of vectors and strings from the standard library (as to avoid any manual memory management issues). More info about the game can be found here: https://en.wikipedia.org/wiki/Hangman_(game)_

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
    - If the letter is part of the word , the places where it occurs are written.
    - If the letter is not part of the word, reduce the number of attempts by 1.
 - When you enter a letter that was entered earlier, the number of attempts is not reduced.
 - Until the number of attempts is complete or the user does not recognize the word, user entered a letters.
 - At the end of the game (exhaustion of the number of attempts), it is written whether the player has known the word or      not and what the word is. Then it returns to the main menu.

        2. SETTINGS

**The settings can change the behavior of the game. Decide for yourself how the game settings will change.
There are 2 possible changes:**
- Change the length of the word. By default, the length of the word is not limited. The player can choose to select words   between 5 and 7 letters, for example.
- Change the number of attempts. By default, the player is entitled to 5 errors. This number can be changed, for example,   to 3 errors.

        3. EXIT

**When this option is selected, the game is exited and the program closes.**




                    Created by: Monnica Mitreva
