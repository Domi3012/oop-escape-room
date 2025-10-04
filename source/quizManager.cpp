#include "../include/quizManager.h"

QuizManager::QuizManager(std::vector<Question> ql, std::string e) : questionList(ql), email(e) {};

void QuizManager::run() {
    // state = -1 -> lua chon cau hoi
    // state = 1, 2, 3 -> display va tra loi cau hoi thu 1, 2 ,3...
    // state = 0 ket thuc quiz session
    int state = -1;
    
    while (state != 0) {
        if (state == -1) {
            state = selectQuestionSession();
            continue;
        }
        else {
            answerQuestionSession(state);
            state = -1;
            continue;
        }
    }

    std::string finalEmail = constructEmail();

    // hien thi email cuoi cung
    clearConsole();
    std::cout << "Chúc mừng các bạn đã hoàn thành thử thách, nếu muốn được hợp tác với mình, xin vui lòng gửi email tới:\n\n";
    std::cout << finalEmail;
    std::cout << "\n\nHãy nhấn phím enter để tiếp tục...";
    std::cin.get();
    std::cin.get();
}

int QuizManager::selectQuestionSession() {
    int newState = 5;
    while (true) {
        clearConsole();
        std::cout << newState << std::endl;
        std::cout << "LỰA CHỌN CÂU HỎI\n";
        std::cout << "Danh sách câu hỏi\n";
        for (int i = 0; i < questionList.size(); i++) {
            std::print(std::cout, "Câu {0}: ", i+1);
            if (!questionList[i].isAnswered()) {
                std::cout << "CHƯA TRẢ LỜI.\n";
            } else {
                std::print(std::cout, "ĐÃ TRẢ LỜI. (Câu trả lời của bạn: {0})\n", questionList[i].getCurrentAnswer());
            }
        }
        std::cout << "\nHƯỚNG DẪN:\n";
        std::print(std::cout, "     - Hãy nhập số thứ tự của câu hỏi (1 - {0}) để lựa câu hỏi muốn nhập câu trả lời.\n", questionList.size());
        std::cout << "     - Nếu đã trả lời tất cả câu hỏi, hãy nhập 0 để kết thúc thử thách và nhận email.\n";
        std::cout << "\nLỰA CHỌN CỦA BẠN: ";

        if (std::cin >> newState) {
            if (newState >= 0 && newState <= questionList.size()) {
                break;
            } else {
                // Số nhập vào nằm ngoài phạm vi cho phép
                std::cout << "Lựa chọn không hợp lệ. Nhấn enter để quay lại màn hình lựa chọn.";
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
            }
        } else {
            std::cout << "Lựa chọn không hợp lệ. Nhấn enter để quay lại màn hình lựa chọn.";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
    } 

    return newState;
}

void QuizManager::answerQuestionSession(int number) {
    clearConsole();
    std::cin.clear(); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear du lieu con lai trong std::cin

    std::print(std::cout, "CÂU HỎI {0}:\n", number);
    questionList[number - 1].displayQuestion();

    std::cout << "\nHãy nhập câu trả lời của bạn: ";
    std::string ans;
    getline(std::cin, ans);

    questionList[number - 1].setAnswer(ans);
}

// Ham xay dung email cuoi cung tu email placeholder va cac key tu cac question da duoc tra loi
std::string QuizManager::constructEmail() {
    std::string finalEmail = email;
    for (Question ques: questionList) {
        std::string key = ques.getKeyFromAnswer();
        int targetIndex = ques.getTargetStartIndex();
        for (int i = 0; i < key.size(); i++) {
            finalEmail[targetIndex + i] = key[i];
        }
    }
    return finalEmail;
}