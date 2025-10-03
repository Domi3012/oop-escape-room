#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./question.h"

void clearConsole();
void greet();
void salute();

void chalengeUseCase();
int quesionSelectSession();
std::string loadEmailFromFile();
std::vector<Question> loadQuestionFromFile();

#endif