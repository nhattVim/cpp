#include <bits/stdc++.h>
using namespace std;

#define MAX_VERTICES 100

// Định nghĩa cấu trúc đồ thị bằng ma trận kề
struct AdjMatrixGraph {
    int numVertices;                           // Số lượng đỉnh
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Ma trận kề
};

// Đọc đồ thị từ tệp và lưu vào cấu trúc đồ thị
void readGraphFromFile(string fileName, AdjMatrixGraph &graph) {
    ifstream file(fileName);
    file >> graph.numVertices;

    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numVertices; j++) {
            file >> graph.adjMatrix[i][j];
        }
    }
    file.close();
}

// In ma trận kề của đồ thị
void printGraph(AdjMatrixGraph graph) {
    cout << "Num of vertices: " << graph.numVertices << endl;
    for (int i = 0; i < graph.numVertices; i++) {
        for (int j = 0; j < graph.numVertices; j++) {
            cout << graph.adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Tìm kiếm theo chiều sâu (DFS) từ một đỉnh
void DFS(const AdjMatrixGraph &graph, int vertex, vector<bool> &visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < graph.numVertices; i++) {
        if (graph.adjMatrix[vertex][i] != 0 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Tìm kiếm theo chiều rộng (BFS) từ một đỉnh
void BFS(const AdjMatrixGraph &graph, int vertex) {
    queue<int> queue;
    vector<bool> visited(MAX_VERTICES, false);

    visited[vertex] = true;
    queue.push(vertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << currVertex << " ";
        queue.pop();

        for (int i = 0; i < graph.numVertices; i++) {
            if (graph.adjMatrix[currVertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

// Đếm tổng số cạnh trong đồ thị
int countEdges(AdjMatrixGraph g) {
    int count = 0;
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            if (g.adjMatrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count / 2; // Chia cho 2 vì mỗi cạnh được đếm 2 lần
}

// Đếm số cạnh vào của một đỉnh x
int countIncomingEdges(AdjMatrixGraph g, int x) {
    int count = 0;
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[i][x] == 1) {
            count++;
        }
    }
    return count;
}

// Liệt kê các đỉnh không kề với đỉnh x
void notAdjacent(AdjMatrixGraph g, int x) {
    bool found = false;
    cout << "Vertices not adjacent to vertex " << x << ": ";
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[x][i] == 0 && x != i) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }
    cout << endl;
}

// Liệt kê các đỉnh không thể đạt đến từ đỉnh x qua DFS
void notVisited(AdjMatrixGraph g, int x) {
    vector<bool> visited(MAX_VERTICES, false);

    DFS(g, x, visited);
    cout << "\nVertices not reachable from vertex " << x << ": ";
    bool found = false;
    for (int i = 0; i < g.numVertices; i++) {
        if (!visited[i]) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "All vertices are reachable";
    }
    cout << endl;
}

// Kiểm tra một dãy các đỉnh có tạo thành đường đi trong đồ thị không
bool isPath(AdjMatrixGraph g, vector<int> arr) {
    int k = arr.size();
    for (int i = 0; i < k - 1; i++) {
        if (g.adjMatrix[arr[i]][arr[i + 1]] == 0) {
            return false;
        }
    }
    return true;
}

// Tìm các đỉnh có đường đi đến đỉnh x
void pathToVertex(AdjMatrixGraph g, int x) {
    bool found = false;
    cout << "All vertices with a path to vertex " << x << ": ";
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[i][x] == 1) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    AdjMatrixGraph g;
    vector<bool> visited(MAX_VERTICES, false);

    readGraphFromFile("Graph1.txt", g);
    printGraph(g);

    cout << "BFS from vertex 0: ";
    BFS(g, 0);
    cout << endl;

    cout << "The number of edges in the graph: " << countEdges(g) << endl;

    cout << "Vertices not adjacent with vertex 1: ";
    notAdjacent(g, 1);

    cout << "DFS and vertices not reachable from vertex 3: ";
    notVisited(g, 3);

    vector<int> a = {0, 1, 2, 4}; // Sử dụng vector thay cho mảng động
    if (isPath(g, a)) {
        cout << "The array represents a path in the graph" << endl;
    } else {
        cout << "The array does not represent a path in the graph" << endl;
    }

    cout << "Vertices with a path to vertex 3: ";
    pathToVertex(g, 3);

    return 0;
}
