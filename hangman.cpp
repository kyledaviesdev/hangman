#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cctype> // For toupper

class Hangman {
    private:
        std::string secretWord;
        std::vector<char> guessedLetters;
        int incorrectGuesses;
        const int maxGuesses = 6;
    
        std::vector<std::string> wordList = {
            "apple", "banana", "orange", "grape", "kiwi", "mango", "beekeeper", "cobweb", "dungeon", "eclipse", "firefly",
        "hacker", "iceberg", "jigsaw", "kangaroo", "labyrinth", "mosaic", "obelisk", "paradox", "quarantine", "rainbow"
        };

    public:
        Hangman() {
            // Initialize random seed (important for different random words each time)
            std::srand(std::time(0));  

            // Choose a random word from the list
            int randomIndex = std::rand() % wordList.size();
            secretWord = wordList[randomIndex];

            guessedLetters.clear(); // Start with no guessed letters
            incorrectGuesses = 0;
        }
        void play() {
            while (!gameOver()) {
                displayGameState();
                char guess = getPlayerGuess();
                processGuess(guess);
            }
            displayResult();
        }
    private:
        void displayGameState() {
            std::cout << "\nSecret word: ";
            for (char letter : secretWord) {
                bool found = false;
                for (char guessed : guessedLetters) {
                    if (std::toupper(letter) == std::toupper(guessed)) { // Case-insensitive comparison
                        std::cout << letter << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "_ ";
                }
            }
            std::cout << "\nGuessed letters: ";
            for (char guessed : guessedLetters) {
                std::cout << guessed << " ";
            }
            std::cout << "\nIncorrect guesses: " << incorrectGuesses << "/" << maxGuesses << std::endl;
        }
        char getPlayerGuess() {
            char guess;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            return guess;
        }
        
        void processGuess(char guess) {
            guess = std::toupper(guess); // Make guess case-insensitive
        
            bool correctGuess = false;
            for (char letter : secretWord) {
                if (std::toupper(letter) == guess) {
                    correctGuess = true;
                    break;
                }
            }
        
            if (correctGuess) {
                bool alreadyGuessed = false;
                for (char guessed : guessedLetters) {
                    if (guessed == guess) {
                        alreadyGuessed = true;
                        break;
                    }
                }
                if (!alreadyGuessed) {
                    guessedLetters.push_back(guess);
                }
            } else {
                incorrectGuesses++;
                bool alreadyGuessed = false;
                for (char guessed : guessedLetters) {
                    if (guessed == guess) {
                        alreadyGuessed = true;
                        break;
                    }
                }
                 if (!alreadyGuessed) {
                    guessedLetters.push_back(guess);
                }
            }
        }
        
        bool gameOver() {
            if (incorrectGuesses >= maxGuesses) {
                return true; // Player lost
            }
        
            bool allLettersGuessed = true;
            for (char letter : secretWord) {
                bool found = false;
                for (char guessed : guessedLetters) {
                    if (std::toupper(letter) == std::toupper(guessed)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    allLettersGuessed = false;
                    break;
                }
            }
            return allLettersGuessed; // Player won
        }
        
        void displayResult() {
            if (incorrectGuesses >= maxGuesses) {
                std::cout << "\nYou lost! The word was: " << secretWord << std::endl;
            } else {
                std::cout << "\nYou won! Congratulations!" << std::endl;
            }
        }
};

int main() {
    Hangman game;
    game.play();
    return 0;
}