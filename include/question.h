#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <format> // for std::print
#include <cctype> // for std::tolower()
#include <algorithm> // for std::transform()

class Question {
private:
    std::string questionText;
    std::string currentAnswer;
    int keyStartIndex;
    int keyLength;
    int targetStartIndex;

    std::string toLowerStr(std::string str);
public:
    Question(std::string qt, int start, int len, int tstart);
    void displayQuestion();
    void setAnswer(std::string ansText);
    std::string getKeyFromAnswer();
    int getTargetStartIndex();
    bool isAnswered();
    std::string getCurrentAnswer();
};

#endif