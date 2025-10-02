#include "../include/question.h"

void Question::displayQuestion() {
    std::print(std::cout, "CÂU HỎI {0}\n", questionID);
    std::cout << questionText << '\n';
}

Question::Question(std::string qt, int id, int start, int len) 
    : questionText(qt), 
      questionID(id), 
      keyStartIndex(start), 
      keyLength(len) 
{}

std::string Question::toLowerStr(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

void Question::setAnswer(std::string ansText) {
    currentAnswer = toLowerStr(ansText);
}

