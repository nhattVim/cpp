#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

typedef struct Node *node;

node createNode(char data) {
    node newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void preOrder(node root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    node root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');
    root->left->left->right = createNode('H');
    root->left->right->left = createNode('I');
    root->left->right->right = createNode('J');
    root->right->right->left = createNode('K');

    cout << "Thứ tự duyệt theo thứ tự trước: ";
    preOrder(root);
    cout << endl;

    cout << "Thứ tự duyệt theo thứ tự giữa: ";
    inOrder(root);
    cout << endl;

    return 0;
}
