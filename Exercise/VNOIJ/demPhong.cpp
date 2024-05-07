// Cho sơ đồ một toàn nhà, hãy đếm xem trong tòa nhà có bao nhiêu phòng. Kích thước của tòa nhà gồm n x m ô vuông,
// mỗi ô có thể là sàn, có thể là tường. Bạn có thể đi sang trái, sang phải, lên trên, xuống dưới thông qua các ô sàn của tòa nhà.
// Input: 
//     - Dòng đầu tiên chứa 2 số nguyên n và m là chiều cao và chiều rộng của tòa nhà
//     - N dòng tiếp theo mỗi dòng chứa m ký tự mô tả, nếu là . đó là sàn, nếu là # đó là tường.
// Output: In ra số phòng của toàn nhà

// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########
// Output 3

#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

void dfs(int i, int j, vector<vector<char>>& building, vector<vector<bool>>& visited) {
    if (i < 0 || i >= building.size() || j < 0 || j >= building[0].size() || visited[i][j] || building[i][j] == '#') {
        return;
    }

    visited[i][j] = true;

    dfs(i - 1, j, building, visited);
    dfs(i + 1, j, building, visited);
    dfs(i, j - 1, building, visited);
    dfs(i, j + 1, building, visited);
}

int countRooms(vector<vector<char>>& building) {
    int n = building.size();
    int m = building[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && building[i][j] == '.') {
                dfs(i, j, building, visited);
                roomCount++;
            }
        }
    }

    return roomCount;
}

int main() {
    IOS;
    int n, m;
    cin >> n >> m;

    vector<vector<char>> building(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> building[i][j];
        }
    }

    int result = countRooms(building);
    cout << result << endl;

    return 0;
}
