#include <bits/stdc++.h>

using namespace std;

#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define INF 1000

struct Edge {
    int startVertex, destVertex;
    float weight;
};

struct EdgeListGraph {
    int numVertices, numEdges;
    Edge edgeList[MAX_EDGES];
};

// Đọc đồ thị từ file
void readGraphFromFile(EdgeListGraph &graph, string fileName) {
    ifstream file(fileName);
    file >> graph.numVertices >> graph.numEdges;

    for (int i = 0; i < graph.numEdges; i++) {
        file >> graph.edgeList[i].startVertex >> graph.edgeList[i].destVertex >>
            graph.edgeList[i].weight;
    }

    file.close();
}

// In ra thông tin của đồ thị
void printGraph(const EdgeListGraph &graph) {
    cout << "Số đỉnh: " << graph.numVertices << endl;
    cout << "Số cạnh: " << graph.numEdges << endl;

    for (int i = 0; i < graph.numEdges; i++) {
        cout << graph.edgeList[i].startVertex << " -> "
             << graph.edgeList[i].destVertex << " (" << graph.edgeList[i].weight
             << ")" << endl;
    }
}

// Hàm DFS để tìm cây bao trùm
void DFSSpanningTree(EdgeListGraph graph, int v, bool visited[],
                     EdgeListGraph &h) {
    visited[v] = true;
    for (int i = 0; i < graph.numEdges; i++) {
        int w;
        if (graph.edgeList[i].startVertex == v) {
            w = graph.edgeList[i].destVertex;
        } else if (graph.edgeList[i].destVertex == v) {
            w = graph.edgeList[i].startVertex;
        } else {
            continue;
        }
        if (!visited[w]) {
            h.edgeList[h.numEdges++] = graph.edgeList[i];
            DFSSpanningTree(graph, w, visited, h);
        }
    }
}

// Tìm cây bao trùm bằng DFS
EdgeListGraph spanningTree(EdgeListGraph graph) {
    EdgeListGraph h;
    h.numVertices = graph.numVertices;
    h.numEdges = 0;
    bool visited[MAX_VERTICES] = {false};
    DFSSpanningTree(graph, 0, visited, h);
    return h;
}

// Hàm BFS để tìm cây bao trùm
void BFSSpanningTree(EdgeListGraph graph, int v, bool visited[],
                     EdgeListGraph &h) {
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph.numEdges; i++) {
            int w;
            if (graph.edgeList[i].startVertex == u) {
                w = graph.edgeList[i].destVertex;
            } else if (graph.edgeList[i].destVertex == u) {
                w = graph.edgeList[i].startVertex;
            } else {
                continue;
            }
            if (!visited[w]) {
                visited[w] = true;
                h.edgeList[h.numEdges++] = graph.edgeList[i];
                q.push(w);
            }
        }
    }
}

// Tìm cây bao trùm bằng BFS
EdgeListGraph spanningTreeBFS(EdgeListGraph graph) {
    EdgeListGraph h;
    h.numVertices = graph.numVertices;
    h.numEdges = 0;
    bool visited[MAX_VERTICES] = {false};
    BFSSpanningTree(graph, 0, visited, h);
    return h;
}

// Hàm DFS để tạo cây bao trùm không chứa một cạnh cụ thể
void DFSSpanningTreeNotEdge(EdgeListGraph graph, int v, bool visited[],
                            EdgeListGraph &h, int x, int y) {
    visited[v] = true;
    for (int i = 0; i < graph.numEdges; i++) {
        int u = graph.edgeList[i].startVertex;
        int w = graph.edgeList[i].destVertex;

        if ((u == x && w == y) || (u == y && w == x)) {
            continue;
        }

        if (u == v && !visited[w]) {
            h.edgeList[h.numEdges++] = graph.edgeList[i];
            DFSSpanningTreeNotEdge(graph, w, visited, h, x, y);
        } else if (w == v && !visited[u]) {
            h.edgeList[h.numEdges++] = graph.edgeList[i];
            DFSSpanningTreeNotEdge(graph, u, visited, h, x, y);
        }
    }
}

// Tìm cây bao trùm không chứa một cạnh cụ thể
EdgeListGraph spanningTreeNotEdge(EdgeListGraph graph, int x, int y) {
    EdgeListGraph h;
    h.numVertices = graph.numVertices;
    h.numEdges = 0;
    bool visited[MAX_VERTICES] = {false};
    DFSSpanningTreeNotEdge(graph, 0, visited, h, x, y);
    return h;
}

// Hàm BFS để tạo cây bao trùm với các cạnh có trọng số <= M
void BFSSpanningTreeLess(EdgeListGraph graph, int v, bool visited[],
                         EdgeListGraph &h, int M) {
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph.numEdges; i++) {
            int w = -1;
            if (graph.edgeList[i].startVertex == u &&
                graph.edgeList[i].weight <= M) {
                w = graph.edgeList[i].destVertex;
            } else if (graph.edgeList[i].destVertex == u &&
                       graph.edgeList[i].weight <= M) {
                w = graph.edgeList[i].startVertex;
            }
            if (w != -1 && !visited[w]) {
                visited[w] = true;
                h.edgeList[h.numEdges++] = graph.edgeList[i];
                q.push(w);
            }
        }
    }
}

// Tìm cây bao trùm với các cạnh có trọng số <= M
EdgeListGraph spanningTreeLess(EdgeListGraph graph, int M) {
    EdgeListGraph h;
    h.numVertices = graph.numVertices;
    h.numEdges = 0;
    bool visited[MAX_VERTICES] = {false};
    BFSSpanningTreeLess(graph, 0, visited, h, M);
    return h;
}

// Hàm hỗ trợ để gộp các thành phần liên thông
void mergeComponents(int component[], int n, int u, int v) {
    int a = component[u], b = component[v];
    for (int i = 0; i < n; i++) {
        if (component[i] == a) {
            component[i] = b;
        }
    }
}

// Hàm so sánh hai cạnh theo trọng số để sắp xếp danh sách cạnh
bool comp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Thuật toán Kruskal để tìm cây bao trùm nhỏ nhất
EdgeListGraph kruskal(EdgeListGraph graph) {
    EdgeListGraph mst;
    mst.numVertices = graph.numVertices;
    mst.numEdges = 0;

    // Sắp xếp danh sách cạnh theo trọng số
    sort(graph.edgeList, graph.edgeList + graph.numEdges, comp);

    // Tạo các thành phần liên thông ban đầu cho mỗi đỉnh
    int component[MAX_VERTICES];
    for (int i = 0; i < graph.numVertices; i++) {
        component[i] = i;
    }

    // Duyệt qua các cạnh và thêm vào MST nếu chúng không tạo chu trình
    for (int i = 0; i < graph.numEdges; i++) {

        int u = graph.edgeList[i].startVertex;
        int v = graph.edgeList[i].destVertex;

        // Nếu u và v thuộc hai thành phần liên thông khác nhau
        if (component[u] != component[v]) {
            // Thêm cạnh vào cây bao trùm nhỏ nhất (MST) và gộp các thành phần
            // liên thông
            mst.edgeList[mst.numEdges++] = graph.edgeList[i];
            mergeComponents(component, mst.numVertices, u, v);
        }
    }

    return mst;
}

int main() {
    EdgeListGraph g;
    readGraphFromFile(g, "Graph6.txt");
    printGraph(g);

    EdgeListGraph h = spanningTree(g);
    cout << "Cây bao trùm của đồ thị là: " << endl;
    printGraph(h);

    int x = 0, y = 1;
    EdgeListGraph h2 = spanningTreeNotEdge(g, x, y);
    cout << "Cây bao trùm của đồ thị không chứa cạnh (" << x << ", " << y
         << ") là: " << endl;
    printGraph(h2);

    int M = 6;
    EdgeListGraph h3 = spanningTreeLess(g, M);
    cout << "Cây bao trùm của đồ thị với các cạnh có trọng số <= " << M
         << " là: " << endl;
    printGraph(h3);

    EdgeListGraph h4 = kruskal(g);
    cout << "Cây bao trùm nhỏ nhất (Kruskal):" << endl;
    printGraph(h4);

    return 0;
}
