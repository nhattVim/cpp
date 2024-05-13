#include <bits/stdc++.h>

using namespace std;

struct balanceTree {
    int key;
    struct balanceTree *left;
    struct balanceTree *right;
    int height;
};

typedef struct balanceTree *node;

int height(node root) {
    if (root == nullptr) {
        return 0;
    }
    return root->height;
}

int getBalance(node n) {
    if (n == nullptr) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

node leftRotate(node x) {
    node y = x->right;
    node T2 = y->left;

    x->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node rightRotate(node y) {
    node x = y->left;
    node T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node insert(node root, int key) {
    if (root == nullptr) {
        return (new balanceTree{key, nullptr, nullptr, 1});
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node minValueNode(node x) {
    node current = x;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

node deleteNode(node root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);

    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);

    } else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            node temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete(temp);
        } else {
            node temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == nullptr) {

        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main(int argc, char *argv[]) {
    node root = nullptr;
    int i, n = 1000;
    for (i = 1; i <= n; i++) {
        root = insert(root, i);
    }
    cout << "Height of tree after insert: " << root->height << endl;

    for (i = 1; i <= n / 2; i++) {
        root = deleteNode(root, i);
    }
    cout << "Height of tree after delete: " << root->height << endl;
    return 0;
}
