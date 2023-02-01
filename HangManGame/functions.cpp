#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

void welcomeMessage() {

    std::cout << "Welcome to the Hangman Game!\n";
    std::cout << "The rules of the game are simple:\n";
    std::cout << "1. Player 1 will choose a word for Player 2 to guess.\n";
    std::cout << "2. Player 2 will have a certain number of chances to guess the letters of the word.\n";
    std::cout << "3. For every incorrect guess, a part of a stick figure will be drawn.\n";
    std::cout << "4. The game is over when either Player 2 guesses the word correctly or the stick figure is fully drawn.\n";
    std::cout << "Good luck to both players!\n"<<"\n";

}

void reciveWord(std::string& word) {

    std::cout << "Enter word for other player to guess: ";
    std::cin >> word;
    std::cout << "\n";

}


//function adds '*' to answer variable to match lenght to word
void createAnswer(std::string& word, std::string& answer) {

    for (int i = 0; i < word.length(); i++) {

        answer += '*';

    }

}

void drawing(std::string plank1 = " ", std::string plank2 = " ", std::string rope = " ", std::string head = " ", std::string thorax = " ", std::string lHand = " ", std::string rHand = " ", std::string lLeg = " ", std::string rLeg = " ") {
    std::cout << plank2 << plank2 << plank2 << plank2 << std::endl;
    std::cout << plank1 << "  " << rope << std::endl;
    std::cout << plank1 << "  " << head << std::endl;
    std::cout << plank1 << " " << lHand << thorax << rHand << std::endl;
    std::cout << plank1 << " " << lLeg << " " << rLeg << std::endl;
    std::cout << plank1 << std::endl;
}

//following function displays current game statuss
void displayStatuss(std::string& answer, int& mistakes, std::vector<char>& wrongGuesess) { 

    switch (mistakes)
    {
    case 1:

        drawing("|");
        break;

    case 2: 

        drawing("|", "_");
        break;

    case 3:

        drawing("|", "_", "|");
        break;

    case 4:

        drawing("|", "_", "|", "O");
        break;

    case 5:

        drawing("|", "_", "|", "O", "|");
        break;

    case 6:

        drawing("|", "_", "|", "O", "|", "/");
        break;

    case 7:

        drawing("|", "_", "|", "O", "|", "/", "\\");
        break;

    case 8:

        drawing("|", "_", "|", "O", "|", "/", "\\", "/");
        break;

    case 9:

        drawing("|", "_", "|", "O", "|", "/", "\\", "/", "\\");
        break;

    default:
        drawing();
    }

    std::cout << answer << "\n";
    
    if (wrongGuesess.size() != 0) {

        std::cout << "wrong guesess: ";

        for (int i = 0; i < wrongGuesess.size(); i++) {

            std::cout << wrongGuesess[i];

            if (i != wrongGuesess.size() - 1) {

                std::cout << ", ";

            }
             
        }

        std::cout << "\n";

     }
    
}

//function asks user for his guess, verifies it is it inputed correctly and if it isnt already used
void makeGuess(std::vector<char>& correctGuesess, std::vector<char>& wrongGuesess, char& guess) {

    std::cout << "Enter your guess: ";
    std::cin >> guess;
    std::cout << "\n";

    while (true) {

        if (std::cin.fail() || !std::isalpha(guess)) {

            std::cout << "Enter single, alphabetic character: ";
            std::cin >> guess;
            std::cout << "\n";
        
        }else {

            if ((std::find(wrongGuesess.begin(), wrongGuesess.end(), guess) != wrongGuesess.end()) || (std::find(correctGuesess.begin(), correctGuesess.end(), guess) != correctGuesess.end())) {

                std::cout << guess << " is already used as guess.";
                std::cout << "Enter new guess: ";
                std::cin >> guess;
                std::cout << "\n";

            }else {

                break;

            }
        
        }

    }

}

void checkGuess(char guess, std::string word, std::string& answer, std::vector<char>& wrongGuess, std::vector<char>& correctGuess, int& mistakes) {
    bool found = false;
    for (std::size_t i = 0; i < word.size(); i++) {

        if (word[i] == guess) {

            found = true;
            answer[i] = guess;
            correctGuess.push_back(guess);

        }

    }

    if (!found) {

        wrongGuess.push_back(guess);
        mistakes++;

    }

}

void winner() {

    std::cout << "you have won";

}