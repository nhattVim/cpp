#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Person {
    string name;
    int yearOfBirth;
};

struct BFT {
    Person data;
    BFT *left, *right;
};

typedef struct BFT *node;

node makeNode(Person p, node left = nullptr, node right = nullptr) {
    return new BFT{p, left, right};
}

node initNode() {
    BFT *n1, *n2, *n3, *n4, *n5, *n6;
    n1 = makeNode({"Nguyen D", 1960}, nullptr, nullptr);
    n2 = makeNode({"Nguyen B", 1930}, nullptr, n1);
    n3 = makeNode({"Nguyen E", 1965}, nullptr, nullptr);
    n4 = makeNode({"Nguyen F", 1970}, nullptr, nullptr);
    n5 = makeNode({"Nguyen C", 1935}, n3, n4);
    n6 = makeNode({"Nguyen A", 1900}, n2, n5);
    return n6;
}

void printBFT(node root) {
    if (root == nullptr)
        return;

    cout << root->data.name << " " << root->data.yearOfBirth << endl;
    printBFT(root->left);
    printBFT(root->right);
}

int countPerson(node root) {
    if (root == nullptr)
        return 0;
    return 1 + countPerson(root->left) + countPerson(root->right);
}

int height(node root) {
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int countPersonLeftThan(node root, int year) {
    if (root == nullptr)
        return 0;

    if (root->data.yearOfBirth >= year)
        return 0;

    return 1 + countPersonLeftThan(root->left, year) +
           countPersonLeftThan(root->right, year);
}

node findPerson(node root, string name) {
    if (root == nullptr)
        return nullptr;

    if (root->data.name == name)
        return root;

    node left = findPerson(root->left, name);
    if (left != nullptr)
        return left;

    return findPerson(root->right, name);
}

void printDescendants(node root, string name) {
    node person = findPerson(root, name);
    if (person == nullptr)
        return;

    printBFT(person->left);
    printBFT(person->right);
}

void printByLevel(node root, int level) {
    if (root == nullptr)
        return;

    if (level == 1) {
        cout << root->data.name << " (" << root->data.yearOfBirth << ")"
             << endl;
    } else {
        printByLevel(root->left, level - 1);
        printByLevel(root->right, level - 1);
    }
}

bool isParent(node root, string parentName, string childName) {
    node parent = findPerson(root, parentName);
    if (parent == nullptr)
        return false;
    else
        return parent->left && parent->left->data.name == childName ||
               parent->right && parent->right->data.name == childName;
}

bool isDescendant(node root, string descendantName, string ancestorName) {
    node ancestor = findPerson(root, ancestorName);
    if (ancestor == nullptr)
        return false;

    node descendant = findPerson(ancestor, descendantName);
    return descendant != nullptr;
}

bool isSibling(node root, string sibling1, string sibling2) {
    if (root == nullptr)
        return false;
    else if (isParent(root, root->data.name, sibling1) &&
             isParent(root, root->data.name, sibling2))
        return true;

    return isSibling(root->left, sibling1, sibling2) ||
           isSibling(root->right, sibling1, sibling2);
}

int levelOfPerson(node root, string name) {
    if (root->data.name == name)
        return 1;

    int h1 = levelOfPerson(root->left, name);
    int h2 = levelOfPerson(root->right, name);

    if (h1 != 0)
        return 1 + h1;
    else if (h2 != 0)
        return 1 + h2;
    else
        return 0;
}

void setPerson(node root, string name, Person p) {
    node person = findPerson(root, name);
    if (person != nullptr)
        person->data = p;
}

bool addPerson(node root, string parentName, Person p) {
    node parent = findPerson(root, parentName);

    if (parent == nullptr)
        return false;
    else if (parent->left == nullptr) {
        parent->left = makeNode(p, nullptr, nullptr);
        return true;
    } else if (parent->right == nullptr) {
        parent->right = makeNode(p, nullptr, nullptr);
        return true;
    }

    return false;
}

int main() {
    // a)
    node root = initNode();

    // b)
    cout << "Binary Family Tree (BFT):" << endl;
    printBFT(root);

    // c)
    cout << "\nNumber of persons in the family tree: " << countPerson(root)
         << endl;

    // d)
    cout << "\nHeight of the family tree: " << height(root) << endl;

    // e)
    cout << "\nYear: ";
    int year;
    cin >> year;
    cout << "\nNum of people before " << year << ": "
         << countPersonLeftThan(root, year) << endl;

    // f)
    string searchName = "Nguyen E";
    cout << "\nName to search: ";
    cin.ignore();
    getline(cin, searchName);
    node person = findPerson(root, searchName);
    if (person != nullptr) {
        cout << "\nFound person: " << person->data.name << " ("
             << person->data.yearOfBirth << ")" << endl;
    } else {
        cout << "\nPerson not found: " << searchName << endl;
    }

    // g)
    string parentName = "Nguyen C", childName = "Nguyen E";
    if (isParent(root, parentName, childName)) {
        cout << endl << parentName << " is a parent of " << childName << endl;
    } else {
        cout << endl
             << parentName << " is not a parent of " << childName << endl;
    }

    // h)
    string levelName = "Nguyen D";
    cout << "\nLevel of " << levelName << ": " << levelOfPerson(root, levelName)
         << endl;

    // i)
    string yName = "Nguyen E", xName = "Nguyen A";
    if (isDescendant(root, yName, xName)) {
        cout << endl << yName << " is a descendants of " << xName << endl;
    } else {
        cout << endl << yName << " is not a descendants of " << xName << endl;
    }

    // j)
    string ancestor = "Nguyen A";
    cout << "\nDescendants of " << ancestor << ":" << endl;
    printDescendants(root, ancestor);

    // k)
    string oldPerson = "Nguyen E";
    Person newPerson = {"Nguyen Q", 1957};
    cout << "\nSet person " << oldPerson << " to " << newPerson.name << endl;
    setPerson(root, oldPerson, newPerson);
    printBFT(root);

    // i)
    string aName = "Nguyen E", bName = "Nguyen F";
    if (isSibling(root, aName, bName)) {
        cout << endl << aName << " is a sibling of " << bName << endl;
    } else {
        cout << endl << aName << " is not a sibling of " << bName << endl;
    }

    // m)
    int level = 3;
    cout << "\nPersons at level " << level << ":" << endl;
    printByLevel(root, level);

    // o)
    Person p = {"Nguyen G", 1980};
    string iName = "Nguyen F";
    cout << "\nAdd person " << p.name << " to " << iName << " ..." << endl;
    if (addPerson(root, iName, p)) {
        cout << "Person " << p.name << " added to " << iName << endl;
        printBFT(root);
    } else {
        if (!findPerson(root, iName)) {
            cout << "Person " << iName << " not found, cancel" << endl;
        } else {
            cout << "Person " << iName << " has 2 children, cancel" << endl;
        }
    }

    return 0;
}
