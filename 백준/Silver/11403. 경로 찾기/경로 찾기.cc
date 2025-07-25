#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> result;
vector<bool> visited;

void dfs(int start, int curr) {
    for (int next = 0; next < n; next++) {
        if (graph[curr][next] == 1 && !visited[next]) {
            visited[next] = true;
            result[start][next] = 1;
            dfs(start, next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    graph.resize(n, vector<int>(n));
    result.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 각 정점에서 DFS
    for (int i = 0; i < n; i++) {
        visited.assign(n, false);
        dfs(i, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
