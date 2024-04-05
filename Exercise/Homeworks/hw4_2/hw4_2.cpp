#include <bits/stdc++.h>
#include <fstream>

using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

struct DLLNode {
    Student data;
    DLLNode *prev, *next;
};

typedef struct DLLNode* node;

node makeNode (Student s) {
    node tmp = new DLLNode();
    tmp->data = s;
    tmp->prev = nullptr;
    tmp->next = nullptr;
    return tmp;
}

void insertFirst (node &a, Student s) {
    node tmp = makeNode(s);
    if (a == nullptr) {
        a = tmp;
    } else {
        
    }
}

node readFile (node a, string filename) {
    fstream file(filename.c_str());
}


int main (int argc, char *argv[]) {
    
    return 0;
}
