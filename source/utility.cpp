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
    std::cout << "Trong khuôn khổ bài tập lý thuyết tuần 1, lớp Phương pháp lập trình hướng đối tượng của thầy Trần Duy Quang, mình xin đem đến cho các bạn bộ thử thách gồm 3 câu đố nhỏ. Câu trả lời cho từng câu hỏi của bạn sẽ đóng góp một phần nhỏ để 'mở khóa' được email của mình.\n\n";
    std::cout << "Nếu các bạn đã sẵn sàng, xin các bạn hãy ấn phím Enter để bắt đầu thử thách...";
    std::cin.get();
}

void salute() {
    clearConsole();
    std::cout << "Cảm ơn các bạn đã tham gia thử thách của mình. Hi vọng đã có một trải nghiệm tốt và mong rằng các bạn đã tìm đúng email của mình!\n";
    std::cout << "Chương trình đang thoát, hãy nhấn phím enter để tiếp tục...";
    std::cin.get();
}

