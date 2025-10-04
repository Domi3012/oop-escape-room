#include "../include/utility.h"

void clearConsole() {
#if defined(_WIN32) || defined(WIN32)
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-based systems
#endif
}

void greet() {
    clearConsole();
    std::cout << "ESCAPE ROOM CHALENGE - THỬ THÁCH 'MỞ KHÓA' EMAIL\n\n";
    std::cout << "Trong khuôn khổ bài tập lý thuyết tuần 1, lớp Phương pháp lập trình hướng đối tượng của thầy Trần Duy Quang, mình xin đem đến cho các bạn bộ thử thách gồm các câu đố nhỏ. Câu trả lời cho từng câu hỏi của bạn sẽ đóng góp một phần nhỏ để 'mở khóa' được email của mình.\n\n";
    std::cout << "Nếu các bạn đã sẵn sàng, xin các bạn hãy ấn phím Enter để bắt đầu thử thách...";
    std::cin.get();
}

void salute() {
    clearConsole();
    std::cout << "Cảm ơn các bạn đã tham gia thử thách của mình. Hi vọng các bạn đã có một trải nghiệm tốt và mong rằng các bạn đã tìm đúng email của mình!\n";
    std::cout << "\nChương trình đang thoát, hãy nhấn phím enter để tiếp tục...";
    std::cin.get();
    std::cin.get();
}

std::string loadEmailFromFile() {
    std::ifstream inFile("data/email.txt");
    
    if (!inFile.is_open()) {
        std::cerr << "Lỗi: Không thể mở file dữ liệu email\n";
        return ""; // Trả về string rỗng để báo hiệu thất bại
    }

    std::string line;
    std::getline(inFile, line);

    return line;
}

std::vector<Question> loadQuestionFromFile() {
    std::ifstream inFile("data/questions.txt");
    std::vector<Question> questions;


    if (!inFile.is_open()) {
        std::cerr << "Lỗi: Không thể mở file dữ liệu câu hỏi\n";
        return questions; // Trả về vector rỗng để báo hiệu thất bại
    }

    std::string line;
    int lineCount = 0;

    while (std::getline(inFile, line)) {
        lineCount++;
        
        if (line.empty()) continue;

        std::string text;
        int startIndex, len, targetIndex;
        std::stringstream ss(line);
        if (
            !std::getline(ss, text, '|') ||
            !(ss >> startIndex) ||
            !(ss >> len) ||
            !(ss >> targetIndex)
        ) {
            std::cerr << "Load câu hỏi: Dòng " << lineCount << " không đúng định dạng. Bỏ qua." << std::endl;
            continue;
        }
        
        questions.push_back(Question(text, startIndex, len, targetIndex));
    }

    return questions;
}
