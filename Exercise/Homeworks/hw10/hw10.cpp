#include <bits/stdc++.h>

using namespace std;

#define MAX_VERTICES 100
#define INF 1000

// Định nghĩa cấu trúc danh sách kề
struct AdjList {
    int adjVertex; // Đỉnh kề
    float weight;  // Trọng số của cạnh
    AdjList *next; // Con trỏ tiếp theo
};

// Định nghĩa cấu trúc đồ thị bằng danh sách kề
struct AdjListGraph {
    int numVertices;                // Số lượng đỉnh
    AdjList *adjList[MAX_VERTICES]; // Mảng các danh sách kề
};

// Đọc đồ thị từ file và lưu vào cấu trúc dữ liệu đồ thị bằng danh sách kề
void readGraphFromFile(AdjListGraph &graph, string fileName) {
    ifstream file(fileName);
    file >> graph.numVertices;

    for (int i = 0; i < graph.numVertices; i++) {
        graph.adjList[i] = nullptr; // Khởi tạo danh sách kề của từng đỉnh
        for (int j = 0; j < graph.numVertices; j++) {
            float weight;
            file >> weight;
            if (weight != INF) {
                // Tạo nút mới để thêm vào danh sách kề của đỉnh i
                AdjList *newNode = new AdjList;
                newNode->adjVertex = j;
                newNode->weight = weight;
                newNode->next = graph.adjList[i];
                graph.adjList[i] = newNode;
            }
        }
    }

    file.close();
}

// In đồ thị dưới dạng danh sách kề
void printGraph(AdjListGraph graph) {
    cout << "Num of vertices: " << graph.numVertices << endl;
    for (int i = 0; i < graph.numVertices; i++) {
        cout << "adjList[" << i << "]: ";
        for (AdjList *p = graph.adjList[i]; p != nullptr; p = p->next) {
            cout << p->adjVertex << "(" << p->weight << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// Tìm đường đi từ đỉnh s đến tất cả các đỉnh khác bằng BFS và lưu parent để tái
// sử dụng
void PathBFS(AdjListGraph graph, int s, int parent[]) {
    bool visited[MAX_VERTICES] = {false};

    for (int i = 0; i < graph.numVertices; i++) {
        parent[i] = -1;
    }
    queue<int> q;
    visited[s] = true;
    parent[s] = s;
    q.push(s);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (AdjList *p = graph.adjList[curr]; p != nullptr; p = p->next) {
            if (!visited[p->adjVertex]) {
                visited[p->adjVertex] = true;
                parent[p->adjVertex] = curr;
                q.push(p->adjVertex);
            }
        }
    }
}

// In đường đi từ đỉnh s đến đỉnh v sử dụng parent array
void printPath(int parent[], int s, int v) {
    if (v == s) {
        cout << s << " ";
        return;
    }
    printPath(parent, s, parent[v]);
    cout << v << " ";
}

// Duyệt đồ thị bằng DFS để kiểm tra tính liên thông
void DFS(AdjListGraph graph, int v, bool visited[]) {
    visited[v] = true;
    for (AdjList *p = graph.adjList[v]; p != nullptr; p = p->next) {
        if (!visited[p->adjVertex]) {
            DFS(graph, p->adjVertex, visited);
        }
    }
}

// Kiểm tra đồ thị có liên thông không
bool isConnected(AdjListGraph graph) {
    bool visited[MAX_VERTICES] = {false};
    DFS(graph, 0, visited);
    for (int i = 0; i < graph.numVertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

// Duyệt từng thành phần liên thông bằng DFS và gán nhãn thành phần
void DFSConnectedComponents(AdjListGraph graph, int v, bool visited[],
                            int component[], int k) {
    visited[v] = true;
    component[v] = k;
    for (AdjList *p = graph.adjList[v]; p != NULL; p = p->next) {
        if (!visited[p->adjVertex]) {
            DFSConnectedComponents(graph, p->adjVertex, visited, component, k);
        }
    }
}

// Đếm số lượng thành phần liên thông và gán nhãn cho từng đỉnh
int connectedComponents(AdjListGraph graph, int component[]) {
    bool visited[MAX_VERTICES] = {false};
    int k = 0; // Số lượng thành phần liên thông
    for (int i = 0; i < graph.numVertices; i++) {
        if (!visited[i]) {
            k++;
            DFSConnectedComponents(graph, i, visited, component, k);
        }
    }
    return k;
}

// In các thành phần liên thông của đồ thị
void printConnectedComponents(int component[], int n, int k) {
    cout << "Num of connected components is: " << k << endl;
    for (int i = 1; i <= k; i++) {
        cout << "Component[" << i << "]: ";
        for (int j = 0; j < n; j++) {
            if (component[j] == i) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Kiểm tra xem có đường đi từ đỉnh src đến đỉnh dest không
bool hasPath(AdjListGraph graph, int src, int dest) {
    if (src == dest) {
        return true;
    }
    bool visited[MAX_VERTICES] = {false};
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (AdjList *p = graph.adjList[curr]; p != nullptr; p = p->next) {
            if (p->adjVertex == dest) {
                return true;
            }
            if (!visited[p->adjVertex]) {
                visited[p->adjVertex] = true;
                q.push(p->adjVertex);
            }
        }
    }
    return false;
}

// Tìm đường đi từ s đến d không đi qua đỉnh v
vector<int> pathNoVertex(AdjListGraph graph, int s, int d, int v) {
    vector<int> path;
    if (s == v || d == v) {
        return path;
    }

    bool visited[MAX_VERTICES] = {false};
    int parent[MAX_VERTICES];
    fill_n(parent, MAX_VERTICES, -1);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (AdjList *p = graph.adjList[curr]; p != nullptr; p = p->next) {
            if (p->adjVertex == v) {
                continue;
            }
            if (!visited[p->adjVertex]) {
                visited[p->adjVertex] = true;
                parent[p->adjVertex] = curr;
                q.push(p->adjVertex);
                if (p->adjVertex == d) {
                    break;
                }
            }
        }
    }
    if (!visited[d]) {
        return path;
    }
    for (int at = d; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    return path;
}

// Tìm đường đi từ s đến d với trọng số các cạnh >= M
vector<int> pathGreatThan(AdjListGraph graph, int s, int d, int M) {
    vector<int> path;

    int visited[MAX_VERTICES] = {false};
    int parent[MAX_VERTICES];
    fill_n(parent, MAX_VERTICES, -1);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (AdjList *p = graph.adjList[curr]; p != nullptr; p = p->next) {
            if (p->weight >= M && !visited[p->adjVertex]) {
                visited[p->adjVertex] = true;
                parent[p->adjVertex] = curr;
                q.push(p->adjVertex);
                if (p->adjVertex == d) {
                    break;
                }
            }
        }
    }

    if (!visited[d]) {
        return path;
    }
    for (int at = d; at != -1; at = parent[at]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    AdjListGraph g;
    readGraphFromFile(g, "Graph4.txt");
    printGraph(g);

    int parent[MAX_VERTICES];
    int s, d;
    cout << "Input start vertex: ";
    cin >> s;
    cout << "Input destination vertex: ";
    cin >> d;

    // Tìm đường đi từ s đến d và in ra
    PathBFS(g, s, parent);
    cout << "A path from " << s << " to " << d << " is: ";
    printPath(parent, s, d);
    cout << endl;

    // Kiểm tra đồ thị có liên thông hay không
    bool connected = isConnected(g);
    if (connected) {
        cout << "Graph is connected." << endl;
    } else {
        cout << "Graph is unconnected." << endl;
    }

    // Tìm và in ra các thành phần liên thông của đồ thị
    int comp[MAX_VERTICES] = {-1};
    int k = connectedComponents(g, comp);
    printConnectedComponents(comp, g.numVertices, k);

    // Tìm và in ra đường đi từ s1 đến từng đỉnh khác trong đồ thị
    int s1;
    cout << "Input start vertex: ";
    cin >> s1;
    PathBFS(g, s1, parent);
    for (int i = 0; i < g.numVertices; i++) {
        if (hasPath(g, s1, i)) {
            cout << "A path from " << s1 << " to " << i << " is: ";
            printPath(parent, s1, i);
            cout << endl;
        } else {
            cout << "No path from " << s1 << " to " << i << endl;
        }
    }

    // Tìm và in ra đường đi từ 4 đến 3, loại bỏ đỉnh 2 trong quá trình tìm
    vector<int> res = pathNoVertex(g, 4, 3, 2);
    if (res.empty()) {
        cout << "No path from 4 to 3 excluding vertex 2";
    } else {
        cout << "A path from 4 to 3 excluding vertex 2 is: ";
        for (int v : res) {
            cout << v << " ";
        }
        cout << endl;
    }

    // Tìm và in ra đường đi từ 6 đến 3 với trọng số các cạnh >= 2
    vector<int> res2 = pathGreatThan(g, 6, 3, 2);
    if (res2.empty()) {
        cout << "No path from 6 to 3 with edges have weight >= 2";
    } else {
        cout << "A path from 6 to 3 with edges have weight >= 2 is: ";
        for (int v : res2) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
