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
};