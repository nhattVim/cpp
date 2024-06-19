#include <bits/stdc++.h>

using namespace std;

// Định nghĩa cấu trúc dữ liệu Word lưu trữ từ tiếng Anh và nghĩa tiếng Việt
// tương ứng
struct Word {
    string english;    // Từ tiếng Anh
    string vietnamese; // Nghĩa tiếng Việt
};

// Định nghĩa cấu trúc dữ liệu EngVietDict cho cây nhị phân tìm kiếm chứa dữ
// liệu là từ điển Anh-Việt
struct EngVietDict {
    Word data; // Dữ liệu là một từ tiếng Anh và nghĩa tiếng Việt
    EngVietDict *left, *right; // Con trỏ tới cây con trái và cây con phải
};

typedef struct EngVietDict *node; // Định nghĩa node là con trỏ tới EngVietDict

// Hàm chèn một từ vào cây nhị phân tìm kiếm
void insertWord(node &root, Word data) {
    if (root == nullptr) {
        root = new EngVietDict; // Tạo một nút mới nếu cây rỗng
        root->data = data;      // Gán dữ liệu cho nút mới
        root->left = root->right =
            nullptr; // Khởi tạo con trỏ trái và phải là nullptr
    } else if (data.english < root->data.english) {
        insertWord(
            root->left,
            data); // Nếu từ tiếng Anh nhỏ hơn từ gốc, chèn vào cây con trái
    } else if (data.english > root->data.english) {
        insertWord(
            root->right,
            data); // Nếu từ tiếng Anh lớn hơn từ gốc, chèn vào cây con phải
    }
}

// Hàm đọc từ điển từ một tệp tin và chèn các từ vào cây nhị phân
void readDictFromFile(node &root, string fileName) {
    fstream f(fileName); // Mở tệp tin để đọc
    string line;
    while (getline(f, line)) { // Đọc từng dòng trong tệp
        int pos =
            line.find(':'); // Tìm vị trí dấu hai chấm phân cách từ và nghĩa
        string eng = line.substr(0, pos);   // Lấy từ tiếng Anh
        string viet = line.substr(pos + 1); // Lấy nghĩa tiếng Việt
        Word data = {
            eng, viet}; // Tạo một đối tượng Word với từ và nghĩa vừa lấy được
        insertWord(root, data); // Chèn từ vào cây nhị phân
    }
    f.close(); // Đóng tệp tin
}

// Hàm in từ điển theo thứ tự từ điển (traverse theo thứ tự trung thứ - in-order
// traversal)
void printDict(node root) {
    if (root) {
        printDict(root->left); // In cây con trái trước
        cout << root->data.english << " : " << root->data.vietnamese
             << endl;           // In từ hiện tại
        printDict(root->right); // In cây con phải sau
    }
}

// Hàm tìm nghĩa tiếng Việt của một từ tiếng Anh
string findVietnamese(node root, string eng) {
    if (root == nullptr) {
        return ""; // Trả về chuỗi rỗng nếu không tìm thấy
    }
    if (root->data.english == eng) {
        return root->data.vietnamese; // Trả về nghĩa tiếng Việt nếu tìm thấy từ
    }
    if (eng < root->data.english) {
        return findVietnamese(
            root->left, eng); // Tìm trong cây con trái nếu từ nhỏ hơn từ gốc
    } else {
        return findVietnamese(
            root->right, eng); // Tìm trong cây con phải nếu từ lớn hơn từ gốc
    }
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây (trái nhất)
node findMin(node root) {
    if (root->left == nullptr) {
        return root; // Trả về nút hiện tại nếu không có nút trái hơn
    }
    return findMin(root->left); // Tiếp tục tìm trong cây con trái
}

// Hàm xóa một từ khỏi cây nhị phân
void deleteWord(node &root, string eng) {
    if (root == NULL) {
        return; // Kết thúc nếu cây rỗng
    }
    if (eng < root->data.english) {
        deleteWord(root->left,
                   eng); // Xóa từ trong cây con trái nếu từ nhỏ hơn từ gốc
    } else if (eng > root->data.english) {
        deleteWord(root->right,
                   eng); // Xóa từ trong cây con phải nếu từ lớn hơn từ gốc
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root; // Xóa nút nếu nó không có con
            root = NULL;
        } else if (root->left == NULL) {
            node temp = root;
            root = root->right; // Thay thế nút bằng cây con phải nếu không có
                                // cây con trái
            delete temp;
        } else if (root->right == NULL) {
            node temp = root;
            root = root->left; // Thay thế nút bằng cây con trái nếu không có
                               // cây con phải
            delete temp;
        } else {
            node temp =
                findMin(root->right); // Tìm nút nhỏ nhất trong cây con phải
            root->data = temp->data; // Thay thế dữ liệu của nút cần xóa bằng dữ
                                     // liệu của nút nhỏ nhất
            deleteWord(
                root->right,
                temp->data.english); // Xóa nút nhỏ nhất trong cây con phải
        }
    }
}

// Hàm in các từ bắt đầu bằng chữ 'H'
void printWordByH(node root) {
    if (root == nullptr) {
        return;
    }
    if (root->data.english[0] == 'H') {
        cout << root->data.english << " : " << root->data.vietnamese
             << endl; // In từ nếu nó bắt đầu bằng 'H'
    }
    printWordByH(root->left);  // Tiếp tục kiểm tra cây con trái
    printWordByH(root->right); // Tiếp tục kiểm tra cây con phải
}

// Hàm đếm số từ có từ điển đứng sau một từ cụ thể
int countAfterAWord(node root, string word) {
    if (root == nullptr) {
        return 0;
    }
    if (root->data.english > word) {
        return countAfterAWord(root->left, word) +
               countAfterAWord(root->right, word) +
               1; // Đếm từ nếu nó lớn hơn từ cụ thể
    } else {
        return countAfterAWord(root->right,
                               word); // Tiếp tục đếm trong cây con phải
    }
}

// Hàm lưu cây nhị phân vào tệp tin theo thứ tự trước (pre-order traversal)
void saveToFilePreorder(node root, const string filename) {
    if (root == nullptr) {
        return;
    }
    fstream f(filename, ios::out | ios::app); // Mở tệp tin để ghi thêm
    if (!f.is_open()) {
        cerr << "Cannot open file for writing." << endl;
        return;
    }
    f << root->data.english << ":" << root->data.vietnamese
      << endl; // Ghi từ hiện tại vào tệp
    f.close();
    saveToFilePreorder(root->left, filename);  // Ghi cây con trái vào tệp
    saveToFilePreorder(root->right, filename); // Ghi cây con phải vào tệp
}

// Hàm main để kiểm thử các chức năng của từ điển
int main(int argc, char *argv[]) {
    node root = nullptr; // Khởi tạo cây rỗng
    string eng, viet;

    // Đọc từ điển từ tệp tin "EVD.txt"
    readDictFromFile(root, "EVD.txt");
    printDict(root); // In từ điển ra màn hình
    cout << "\n\n";

    // Tìm nghĩa tiếng Việt của một từ tiếng Anh
    cout << "Input a english: ";
    cin >> eng;
    viet = findVietnamese(root, eng);
    if (viet != "")
        cout << eng << ": " << viet << endl;
    else
        cout << eng << " not found in dictionary." << endl;
    cout << "\n\n";

    // Xóa từ "Hello" khỏi từ điển
    deleteWord(root, "Hello");
    printDict(root); // In lại từ điển sau khi xóa
    cout << "\n\n";

    // In các từ bắt đầu bằng chữ 'H'
    printWordByH(root);
    cout << "\n\n";

    // Đếm số từ sau từ "Book" trong từ điển
    string t = "Book";
    int count = countAfterAWord(root, t);
    cout << "There are '" << count << "' word after " << t << endl;

    // Lưu từ điển vào tệp tin "test.txt" theo thứ tự trước
    saveToFilePreorder(root, "test.txt");

    return 0;
}
