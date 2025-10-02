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
    int questionID;
    int keyStartIndex;
    int keyLength;

    std::string toLowerStr(std::string str);
public:
    Question(std::string qt, int id, int start, int end);
    void displayQuestion();
    void setAnswer(std::string ansText);
    std::string getKeyFromAnswer() {
        
    }
};




#endif