/**
 * @file utility.h
 * @brief Khai báo các hàm tiện ích chung cho chương trình.
 *
 * Bao gồm các hàm để dọn dẹp giao diện console, hiển thị các thông điệp,
 * và quan trọng nhất là các hàm để tải dữ liệu từ file.
 * @note Trong các thiết kế lớn hơn, các hàm tải dữ liệu nên được tách ra
 *       thành một module riêng (ví dụ: FileParser).
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./question.h"

void clearConsole();
void greet();
void salute();

void chalengeUseCase();
int quesionSelectSession();
std::string loadEmailFromFile();
std::vector<Question> loadQuestionFromFile();

#endif