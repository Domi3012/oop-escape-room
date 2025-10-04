#include "../include/question.h"

void Question::displayQuestion() {
    std::cout << questionText << '\n';
}

Question::Question(std::string qt, int start, int len, int tstart) 
    : questionText(qt), 
      keyStartIndex(start), 
      keyLength(len), 
      targetStartIndex(tstart)
{}

std::string Question::toLowerStr(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

void Question::setAnswer(std::string ansText) {
    currentAnswer = toLowerStr(ansText);
}

std::string Question::getKeyFromAnswer() {
    return currentAnswer.substr(keyStartIndex, keyLength);
}

int Question::getTargetStartIndex() {
    return targetStartIndex;
}

bool Question::isAnswered() {
    return !(currentAnswer.empty());
}

std::string Question::getCurrentAnswer() {
    return currentAnswer;
}

