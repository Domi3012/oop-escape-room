/**
 * @file quizManager.h
 * @brief Định nghĩa lớp QuizManager, bộ não điều khiển toàn bộ luồng của thử thách.
 *
 * Lớp này quản lý vòng lặp chính của trò chơi, xử lý việc lựa chọn câu hỏi,
 * nhận câu trả lời, và cuối cùng là xây dựng email kết quả.
 */

#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "../include/utility.h"
#include "../include/question.h"
#include <vector>
#include <iostream>

class QuizManager {
private:
    std::vector<Question> questionList;
    std::string email;
    int selectQuestionSession();
    void answerQuestionSession(int number);
    std::string constructEmail();
public:
    QuizManager(std::vector<Question> ql, std::string e);
    void run();
};

#endif
