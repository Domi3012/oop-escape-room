#include "../include/utility.h"
#include "../include/quizManager.h"
#include "../include/question.h"

int main() {
    greet();
    
    std::vector<Question> questionList = loadQuestionFromFile();
    std::string email = loadEmailFromFile();
    
    QuizManager manager(questionList, email);
    
    manager.run();
    
    salute();
    return 0;
}