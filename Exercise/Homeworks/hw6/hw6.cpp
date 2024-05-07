#include <bits/stdc++.h>

using namespace std;

struct Word {
    string english;
    string vietnamese;
};

struct EngVietDict {
    Word data;
    EngVietDict *left, *right;
};

typedef struct EngVietDict *node;

void insertWord(node &root, Word data) {
    if (root == nullptr) {
        root = new EngVietDict;
        root->data = data;
        root->left = root->right = nullptr;
    } else if (data.english < root->data.english) {
        insertWord(root->left, data);
    } else if (data.english > root->data.english) {
        insertWord(root->right, data);
    }
}

void readDictFromFile(node &root, string fileName) {
    fstream f(fileName);
    string line;
    while (getline(f, line)) {
        int pos = line.find(':');
        string eng = line.substr(0, pos);
        string viet = line.substr(pos + 1);
        Word data = {eng, viet};
        insertWord(root, data);
    }
    f.close();
}

void printDict(node root) {
    if (root) {
        printDict(root->left);
        cout << root->data.english << " : " << root->data.vietnamese << endl;
        printDict(root->right);
    }
}

string findVietnamese(node root, string eng) {
    if (root == nullptr) {
        return "";
    }
    if (root->data.english == eng) {
        return root->data.vietnamese;
    }
    if (eng < root->data.english) {
        return findVietnamese(root->left, eng);
    } else {
        return findVietnamese(root->right, eng);
    }
}

node findMin(node root) {
    if (root->left == nullptr) {
        return root;
    }
    return findMin(root->left);
}

void deleteWord(node &root, string eng) {
    if (root == NULL) {
        return;
    }
    if (eng < root->data.english) {
        deleteWord(root->left, eng);
    } else if (eng > root->data.english) {
        deleteWord(root->right, eng);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            node temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            node temp = root;
            root = root->left;
            delete temp;
        } else {
            node temp = findMin(root->right);
            root->data = temp->data;
            deleteWord(root->right, temp->data.english);
        }
    }
}

void printWordByH(node root) {
}

int main(int argc, char *argv[]) {
    node root = nullptr;
    string eng, viet;
    readDictFromFile(root, "EVD.txt");
    printDict(root);
    cout << "\n\n";

    cout << "Input a english ";
    cin >> eng;
    viet = findVietnamese(root, eng);
    if (viet != "")
        cout << eng << ": " << viet << endl;
    else
        cout << eng << " not found in dictionary." << endl;
    cout << "\n\n";

    deleteWord(root, "Hello");
    printDict(root);
    return 0;
}
