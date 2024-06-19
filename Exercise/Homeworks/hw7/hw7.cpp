#include <bits/stdc++.h>

using namespace std;

// Định nghĩa cấu trúc dữ liệu Person lưu trữ thông tin về một người
struct Person {
    string name;
    int yearOfBirth;
};

// Định nghĩa cấu trúc dữ liệu Family Tree (FT) cho cây phả hệ
struct FT {
    Person data;
    FT *child, *sibling;
};

typedef struct FT *node; // Định nghĩa node là con trỏ tới FT

// Hàm tạo một nút mới trong cây
node makeNode(Person p, node child = nullptr, node sibling = nullptr) {
    return new FT{p, child, sibling};
}

// Hàm khởi tạo cây phả hệ với cấu trúc cụ thể
node initNode() {
    FT *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
    n1 = makeNode({"Nguyen H", 1970}, nullptr, nullptr);
    n2 = makeNode({"Nguyen G", 1965}, nullptr, n1);
    n3 = makeNode({"Nguyen F", 1965}, nullptr, nullptr);
    n4 = makeNode({"Nguyen E", 1960}, nullptr, n3);
    n5 = makeNode({"Nguyen D", 1955}, nullptr, n4);
    n6 = makeNode({"Nguyen C", 1935}, n2, nullptr);
    n7 = makeNode({"Nguyen B", 1930}, n5, n6);
    n8 = makeNode({"Nguyen A", 1900}, n7, nullptr);
    return n8;
}

// Hàm duyệt và in cây phả hệ theo chiều rộng (Breadth-First Search)
void printNodeBFS(node root) {
    if (root == nullptr)
        return;

    queue<node> q;
    q.push(root);

    while (!q.empty()) {
        node current = q.front();
        q.pop();

        // In thông tin người hiện tại
        cout << current->data.name << " (" << current->data.yearOfBirth << ")"
             << endl;

        // Thêm các con của người hiện tại vào hàng đợi
        node child = current->child;
        while (child != nullptr) {
            q.push(child);
            child = child->sibling;
        }
    }
}

// Hàm đếm số người trong cây phả hệ
int countPerson(node root) {
    if (root == nullptr)
        return 0;

    int count = 1;
    node child = root->child;
    while (child != nullptr) {
        count += countPerson(child);
        child = child->sibling;
    }
    return count;
}

// Hàm tính chiều cao của cây phả hệ
int height(node root) {
    if (root == nullptr)
        return 0;

    int max_height = 0;
    node child = root->child;
    while (child != nullptr) {
        max_height = max(max_height, height(child));
        child = child->sibling;
    }
    return max_height + 1;
}

// Hàm tìm kiếm một người trong cây phả hệ theo tên
node search(node root, string name) {
    if (root == nullptr)
        return nullptr;

    if (root->data.name == name)
        return root;

    node child = root->child;
    while (child != nullptr) {
        node result = search(child, name);
        if (result != nullptr)
            return result;
        child = child->sibling;
    }
    return nullptr;
}

// Hàm kiểm tra xem một người có phải là con của người khác không
bool isChild(node root, string parentName, string childName) {
    node parent = search(root, parentName);
    if (parent == nullptr)
        return false;

    node child = parent->child;
    while (child != nullptr) {
        if (child->data.name == childName)
            return true;
        child = child->sibling;
    }
    return false;
}

// Hàm thêm một đứa con mới vào cây phả hệ
void insertChild(node root, string parentName, Person newChild) {
    node parent = search(root, parentName);
    if (parent == nullptr)
        return;

    node newNode = makeNode(newChild);
    if (parent->child == nullptr ||
        parent->child->data.yearOfBirth > newChild.yearOfBirth) {
        newNode->sibling = parent->child;
        parent->child = newNode;
    } else {
        node current = parent->child;
        while (current->sibling != nullptr &&
               current->sibling->data.yearOfBirth < newChild.yearOfBirth) {
            current = current->sibling;
        }
        newNode->sibling = current->sibling;
        current->sibling = newNode;
    }
}

// Hàm in tất cả các hậu duệ của một người
void printDescendants(node root, string name) {
    node person = search(root, name);
    if (person == nullptr)
        return;

    node child = person->child;
    while (child != nullptr) {
        cout << child->data.name << " (" << child->data.yearOfBirth << ")"
             << endl;
        child = child->sibling;
    }
}

// Hàm in các người ở cấp độ k trong cây phả hệ
void printByLevel(node root, int level) {
    if (root == nullptr)
        return;

    if (level == 1) {
        cout << root->data.name << " (" << root->data.yearOfBirth << ")"
             << endl;
    } else {
        node child = root->child;
        while (child != nullptr) {
            printByLevel(child, level - 1);
            child = child->sibling;
        }
    }
}

// Hàm tính số lượng con của một node
int degree(node root) {
    if (root == nullptr)
        return 0;

    int count = 0;
    node child = root->child;
    while (child != nullptr) {
        count++;
        child = child->sibling;
    }
    return count;
}

// Hàm tìm cha mẹ của một người
node findParent(node root, string name) {
    if (root == nullptr || root->child == nullptr)
        return nullptr;

    node child = root->child;
    while (child != nullptr) {
        if (child->data.name == name)
            return root;
        node parent = findParent(child, name);
        if (parent != nullptr)
            return parent;
        child = child->sibling;
    }
    return nullptr;
}

// Hàm tìm anh chị em của một người
node findSibling(node root, string name) {
    if (root == nullptr || root->child == nullptr)
        return nullptr;

    node child = root->child;
    while (child != nullptr) {
        if (child->sibling != nullptr && child->sibling->data.name == name) {
            return child;
        }
        node sibling = findSibling(child, name);
        if (sibling != nullptr)
            return sibling;
        child = child->sibling;
    }
    return nullptr;
}

// Hàm xóa một người theo tên khỏi cây phả hệ
void deleteByName(node root, string name) {
    if (root == nullptr || root->data.name == name) {
        cout << "Cannot delete the root node or a null node" << endl;
        return;
    }

    node parent = findParent(root, name);
    if (parent == nullptr)
        return;

    node current = parent->child;
    node prev = nullptr;

    while (current != nullptr && current->data.name != name) {
        prev = current;
        current = current->sibling;
    }

    if (current != nullptr) {
        if (prev == nullptr) {
            parent->child = current->sibling;
        } else {
            prev->sibling = current->sibling;
        }
        delete current;
    }
}

int main() {
    // Khởi tạo cây phả hệ
    node root = initNode();

    // In cây phả hệ theo thứ tự BFS
    cout << "Family Tree (BFS):" << endl;
    printNodeBFS(root);

    // Đếm số người trong cây phả hệ
    cout << "Number of persons in the family tree: " << countPerson(root)
         << endl;

    // Tính chiều cao của cây phả hệ
    cout << "Height of the family tree: " << height(root) << endl;

    // Tìm kiếm một người theo tên
    string searchName = "Nguyen E";
    node person = search(root, searchName);
    if (person != nullptr) {
        cout << "Found person: " << person->data.name << " ("
             << person->data.yearOfBirth << ")" << endl;
    } else {
        cout << "Person not found: " << searchName << endl;
    }

    // Kiểm tra xem một người có phải là con của người khác không
    string parentName = "Nguyen C", childName = "Nguyen G";
    if (isChild(root, parentName, childName)) {
        cout << childName << " is a child of " << parentName << endl;
    } else {
        cout << childName << " is not a child of " << parentName << endl;
    }

    // Thêm một người con mới vào cây phả hệ
    Person newChild = {"Nguyen Q", 1957};
    insertChild(root, "Nguyen B", newChild);

    // In lại cây phả hệ sau khi thêm
    cout << "Family Tree after adding Nguyen Q:" << endl;
    printNodeBFS(root);

    // In tất cả các hậu duệ của một người
    string ancestor = "Nguyen B";
    cout << "Descendants of " << ancestor << ":" << endl;
    printDescendants(root, ancestor);

    // In các người ở cấp độ 3
    cout << "Persons at level 3:" << endl;
    printByLevel(root, 3);

    // Tính số lượng con của node root
    cout << "Degree of the root: " << degree(root) << endl;

    // Xóa một người theo tên khỏi cây phả hệ
    string deleteName = "Nguyen G";
    deleteByName(root, deleteName);

    // In lại cây phả hệ sau khi xóa
    cout << "Family Tree after deleting " << deleteName << ":" << endl;
    printNodeBFS(root);

    return 0;
}
