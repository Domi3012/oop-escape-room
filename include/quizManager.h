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
public:
    QuizManager(std::vector<Question> ql, std::string e);
    void run();
};

#endif
