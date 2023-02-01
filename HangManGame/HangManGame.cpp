// HangManGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "header.h"
        

int main()
{

    while (true) {
        
        std::string word;
        std::string answer;
        char guess = ' ';
        int mistakes = 0;
        std::vector<char> correctGuesess = {};
        std::vector<char> wrongGuesess = {};
        bool gameOngoing = true;

        system("cls");//makes sure console is clear when starting program
        
        //function displays welcome message and basic rules
        welcomeMessage();
       
        reciveWord(word); //get user input
        
        createAnswer(word, answer);

        while (mistakes < 9) {

            displayStatuss(answer , mistakes, wrongGuesess);//displays curent state of game

            // checks if there is any * left in answer - if yes, it continues - if no it breaks out of loop and finishes this round displaying winner message
            std::size_t found = answer.find('*');
            if (found == std::string::npos) {
                std::cout << "You won!\n";
                break;
            }

            makeGuess(correctGuesess, wrongGuesess,guess);//made guess input

            /*
            checks if guess is in word - if not mistakes++ and pushes guess to wrong guesess vector 

            loops trough wordand if guess is in word, replaces '*' in answer in same index as it is in word
            */
            checkGuess(guess, word, answer, wrongGuesess, correctGuesess, mistakes);

            // clear console for new turn
            system("cls");
        }

        if (mistakes == 9) {
            displayStatuss(answer, mistakes, wrongGuesess);
            std::cout << "You lost!\n Correct word was: " << word << "\n";
            

        }

        //loop asks ifplayer wants to play another round, if not, it closes the app
        while (true) {
            std::cout << "Do you want to continue (y/n)? ";
            std::string response;
            std::cin >> response;

            if (response == "y") {

                break;

            }else if (response == "n") {

                std::cout << "Thanks for playing.";

                return 0;

            }else {

                std::cout << "Invalid input, please enter 'y' or 'n'" << std::endl;
            }

        }

    }
}
