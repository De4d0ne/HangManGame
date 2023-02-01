#pragma once

#include <iostream>
#include <vector>

void welcomeMessage();
void reciveWord(std::string& word);
void createAnswer(std::string& word, std::string& answer);
void displayStatuss(std::string& answer, int& mistakes, std::vector<char>& wrongGuesess);
void makeGuess(std::vector<char>& correctGuesess, std::vector<char>& wrongGuesess, char& guess);
void checkGuess(char guess, std::string word, std::string& answer, std::vector<char>& wrongGuess, std::vector<char>& correctGuess, int& mistakes);

void winner();