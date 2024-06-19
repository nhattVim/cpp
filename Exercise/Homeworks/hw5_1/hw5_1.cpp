#include <bits/stdc++.h>

using namespace std;

// Định nghĩa cấu trúc dữ liệu Person chứa tên và năm sinh của một người
struct Person {
    string name;
    int yearOfBirth;
};

// Định nghĩa cấu trúc dữ liệu BFT cho cây nhị phân với dữ liệu kiểu Person
struct BFT {
    Person data;
    BFT *left, *right;
};

typedef struct BFT *node;

// Tạo một nút mới cho cây nhị phân với dữ liệu là một người và hai con trái, phải
node makeNode(Person p, node l, node r) {
    return new BFT{p, l, r};
}

// Khởi tạo một cây nhị phân đã có sẵn dữ liệu (cây mẫu)
node initialBFT() {
    node n1, n2, n3, n4, n5, n6;

    // Tạo các nút với dữ liệu của từng người và liên kết các nút để tạo cây
    n1 = makeNode({"Nguyen D", 1960}, nullptr, nullptr);
    n2 = makeNode({"Nguyen B", 1930}, nullptr, n1);
    n3 = makeNode({"Nguyen E", 1965}, nullptr, nullptr);
    n4 = makeNode({"Nguyen F", 1970}, nullptr, nullptr);
    n5 = makeNode({"Nguyen C", 1935}, n3, n4);
    n6 = makeNode({"Nguyen A", 1900}, n2, n5);

    return n6;
}

// Hàm in cây nhị phân theo thứ tự trước (pre-order traversal)
void printBFT(node root) {
    if (root) {
        cout << root->data.name << " " << root->data.yearOfBirth << endl;
        printBFT(root->left);
        printBFT(root->right);
    }
}

// Đếm số lượng người trong cây nhị phân
int countPersons(node root) {
    if (!root)
        return 0;
    return 1 + countPersons(root->left) + countPersons(root->right);
}

// Tính chiều cao của cây nhị phân
int height(node root) {
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Đếm số người có năm sinh nhỏ hơn một năm cụ thể
int countPersonsLessThan(node root, int year) {
    if (!root) {
        return 0;
    } else if (root->data.yearOfBirth < year) {
        return countPersonsLessThan(root->left, year) +
               countPersonsLessThan(root->right, year) + 1;
    } else {
        return 0;
    }
}

// Tìm kiếm một người trong cây theo tên
node findPerson(node root, string name) {
    if (!root)
        return nullptr;
    if (root->data.name == name)
        return root;
    if (findPerson(root->left, name))
        return findPerson(root->left, name);
    return findPerson(root->right, name);
}

// Kiểm tra xem một người có phải là cha/mẹ của người khác không
bool isParent(node root, string pName, string cName) {
    node parent;
    parent = findPerson(root, pName);
    if (!parent) {
        return false;
    } else {
        return (parent->left && parent->left->data.name == cName) ||
               (parent->right && parent->right->data.name == cName);
    }
}

// Tìm cấp độ (mức) của một người trong cây nhị phân
int levelOfPerson(node root, string name) {
    if (!root)
        return 0;
    if (root->data.name == name)
        return 1;
    if (findPerson(root->left, name))
        return levelOfPerson(root->left, name) + 1;
    return levelOfPerson(root->right, name) + 1;
}

// Kiểm tra xem một người có phải là hậu duệ của người khác không
bool isDescendant(node root, string parent, string child) {
    if (!root)
        return false;
    if (findPerson(findPerson(root, parent)->left, child)) {
        return true;
    } else if (findPerson(findPerson(root, parent)->right, child)) {
        return true;
    }
    return false;
}

// In danh sách các hậu duệ của một người
void printDesccendant(node root, string name) {
    if (findPerson(root, name)) {
        printBFT(findPerson(root, name)->left);
        printBFT(findPerson(root, name)->right);
    }
}

// Cập nhật thông tin của một người trong cây
void setPerson(node root, string x, Person p) {
    if (findPerson(root, x)) {
        findPerson(root, x)->data = p;
    }
}

// Kiểm tra xem hai người có phải là anh/chị/em không
bool isSibling(node root, string x, string y) {
    if (root == nullptr) {
        return false;
    }
    if (isParent(root, root->data.name, x) &&
        isParent(root, root->data.name, y)) {
        return true;
    } else {
        return isSibling(root->left, x, y) || isSibling(root->right, x, y);
    }
}

// Kiểm tra xem hai cây nhị phân có giống hệt nhau không
bool isSameBFT(node root1, node root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 != nullptr && root2 != nullptr &&
               root1->data.name == root2->data.name &&
               root1->data.yearOfBirth == root2->data.yearOfBirth) {
        return isSameBFT(root1->left, root2->left) &&
               isSameBFT(root1->right, root2->right);
    } else {
        return false;
    }
}

// Thêm một người vào cây như là con của một người khác
bool addPerson(node root, string x, Person p) {
    if (findPerson(root, x)->left && findPerson(root, x)->right) {
        return false;
    } else {
        if (findPerson(root, x)->left == nullptr) {
            findPerson(root, x)->left = makeNode(p, nullptr, nullptr);
        } else {
            findPerson(root, x)->right = makeNode(p, nullptr, nullptr);
        }
        return true;
    }
}

// Chương trình chính
int main(int argc, char *argv[]) {
    node root;
    root = initialBFT();
    printBFT(root);
    cout << "Number of persons in BTS is: " << countPersons(root) << endl;
    cout << "Height of BTS is: " << height(root) << endl;

    cout << "\n\n";
    if (findPerson(root, "Nguyen E")) {
        cout << findPerson(root, "Nguyen E")->data.name << " "
             << findPerson(root, "Nguyen E")->data.yearOfBirth << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "\n\n";
    cout << "Number persons YOB < 1965 is: " << countPersonsLessThan(root, 1965)
         << endl;

    cout << "\n\n";
    string pName = "Nguyen B", cName = "Nguyen E";
    if (isParent(root, pName, cName)) {
        cout << pName << " is parent of " << cName << endl;
    } else {
        cout << pName << " is not parent of " << cName << endl;
    }

    cout << "\n\n";
    string levelName = "Nguyen F";
    cout << "Level of " << levelName
         << " is: " << levelOfPerson(root, levelName) << endl;

    cout << "\n\n";
    string parent = "Nguyen B", child = "Nguyen D";
    if (isDescendant(root, parent, child)) {
        cout << child << " is descendant of " << parent << endl;
    } else {
        cout << child << " is not descendant of " << parent << endl;
    }

    cout << "\n\n";
    string xName = "Nguyen C";
    cout << "List of all descendant of " << xName << ": " << endl;
    printDesccendant(root, xName);

    cout << "\n\n";
    Person p = {"Nguyen M", 2004};
    setPerson(root, "Nguyen C", p);
    printBFT(root);

    cout << "\n\n";
    if (isSibling(root, "Nguyen E", "Nguyen F")) {
        cout << "Nguyen E and Nguyen F is sibling";
    }

    cout << "\n\n";
    node newRoot = initialBFT();
    if (isSameBFT(root, newRoot)) {
        cout << "root == newRoot";
    } else {
        cout << "root != newRoot";
    }

    cout << "\n\n";
    Person newP = {"Nguyen N", 1985};
    if (addPerson(root, "Nguyen B", newP)) {
        cout << "Added a child to " << "Nguyen B" << " sucessfully" << endl;
    } else {
        cout << "Added a child to " << "Nguyen B" << " failed" << endl;
    }
    printBFT(root);
    return 0;
}
