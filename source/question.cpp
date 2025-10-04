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
    if (keyStartIndex < 0 || keyStartIndex >= currentAnswer.length()) {
        return "";
    }
    size_t availableLength = currentAnswer.length() - keyStartIndex;
    size_t lengthToTake = std::min((size_t)keyLength, availableLength);
    return currentAnswer.substr(keyStartIndex, lengthToTake);
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

