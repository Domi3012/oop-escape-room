/**
 * @file question.h
 * @brief Định nghĩa lớp Question, đại diện cho một câu hỏi trong thử thách.
 *
 * Lớp này đóng gói toàn bộ dữ liệu và hành vi liên quan đến một câu hỏi,
 * bao gồm nội dung, thông tin để trích xuất "key" từ câu trả lời,
 * và trạng thái trả lời của người dùng.
 */

#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <math.h>
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