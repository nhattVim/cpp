#include <bits/stdc++.h>

using namespace std;

struct Person {
    string name;
    int yearOfBirth;
};

struct FT {
    Person data;
    FT *child, *sibling;
};

typedef struct FT *node;

node makeNode(Person p, node child, node sibling) {
    return new FT{p, child, sibling};
}

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

void printNodeBFS(node root) {
    queue<node> q;
    node p;
    if (root) {
    }
}

int main(int argc, char *argv[]) {

    return 0;
}
