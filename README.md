# oop-escape-room
Theory exercise #1 for "Object-oriented Programming" course, class 24CTT1, semester 1/2025-2026

## Thông tin sinh viên:
- Họ và tên: **Nguyễn Đức Anh Khôi**
- MSSV: **24120076**


# OOP Assignment 1 - Thử Thách "Mở Khóa" Email

Đây là bài tập đầu tiên cho môn học Phương pháp Lập trình Hướng đối tượng. Chương trình là một trò chơi giải đố nhỏ, nơi người chơi phải trả lời các câu hỏi để tìm ra các mảnh ghép và xây dựng nên email liên hệ của tác giả.

## Tính năng

-   **Giao diện tương tác:** Giao diện người dùng trên nền console, cho phép người chơi tự do lựa chọn câu hỏi.
-   **Hệ thống câu đố linh hoạt:** Các câu hỏi và cơ chế "mở khóa" email được tải từ file ngoài, cho phép dễ dàng thay đổi mà không cần biên dịch lại mã nguồn.
-   **Trạng thái phiên chơi:** Chương trình lưu lại các câu hỏi đã được trả lời, giúp người chơi theo dõi tiến trình.
-   **Xử lý lỗi input:** Chương trình có khả năng xử lý các trường hợp người dùng nhập dữ liệu không hợp lệ.

## Cấu trúc Project

-   `/data/`: Chứa các file dữ liệu.
    -   `email.txt`: Chứa mẫu email với các ký tự cần được thay thế.
    -   `questions.txt`: Chứa danh sách các câu hỏi, mỗi dòng tương ứng một câu.
-   `/include/`: Chứa các file header (`.h`) khai báo các lớp và hàm.
-   `/source/`: Chứa các file mã nguồn (`.cpp`) cài đặt chi tiết.
-   `/build/`: Thư mục chứa file thực thi sau khi biên dịch.

## Hướng dẫn Biên dịch và Chạy

### Yêu cầu

-   Một trình biên dịch C++ hỗ trợ C++20 (do sử dụng `std::format`)

### Biên dịch

1.  Mở terminal và di chuyển vào thư mục gốc của project.
    ```bash
    $ cd oop-escape-room
    ```
2.  Tạo thư mục `build` nếu chưa có:
    ```bash
    $ mkdir -p build
    ```
3.  Biên dịch tất cả các file nguồn:
    ```bash
    $ g++ -std=c++20 source/*.cpp -o build/app
    ```
4.  Chạy chương trình:
    ```bash
    ./build/app
    ```
    **Lưu ý:** Hãy đảm bảo bạn chạy chương trình từ thư mục gốc của project để nó có thể tìm thấy thư mục `data`.

``

## Tái sử dụng chương trình bằng email và bộ câu hỏi khác.

Nếu có nhu cầu datatái sử dụng chương trình, sử dụng chính email và bộ câu hỏi của các bạn, các bạn chỉ cần thay đổi các file sau trong folder /data

### `questions.txt`

Mỗi dòng trong file này đại diện cho một câu hỏi và có định dạng sau:
`Nội dung câu hỏi|startIndex keyLength targetIndex`

-   `|`: Ký tự phân tách.
-   `startIndex`: Vị trí bắt đầu (tính từ 0) để trích xuất "key" từ câu trả lời của người dùng.
-   `keyLength`: Độ dài của "key" cần trích xuất.
-   `targetIndex`: Vị trí bắt đầu (tính từ 0) trong chuỗi email để thay thế bằng "key".

### `email.txt`

File này chứa một dòng duy nhất là mẫu email, với các ký tự placeholder (ví dụ: `#`) sẽ được thay thế bởi các "key" tìm được.

---

Chúc bạn có một buổi review thành công và sẽ được hợp tác với nhóm mình mong muốn!