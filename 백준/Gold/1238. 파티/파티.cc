#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m, x;
vector<vector<pair<int, int>>> graph;      // 원래 방향 그래프
vector<vector<pair<int, int>>> reverse_graph; // 역방향 그래프

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& g) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, weight] : g[now]) {
            int new_cost = cost + weight;
            if (new_cost < dist[next]) {
                dist[next] = new_cost;
                pq.push({new_cost, next});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;

    graph.resize(n + 1);
    reverse_graph.resize(n + 1);

    // 그래프 입력 (정방향 + 역방향)
    for (int i = 0; i < m; i++) {
        int from, to, time;
        cin >> from >> to >> time;
        graph[from].push_back({to, time});
        reverse_graph[to].push_back({from, time});
    }

    // X → 모든 노드 (정방향)
    vector<int> to_all = dijkstra(x, graph);
    
    // 모든 노드 → X (역방향)
    vector<int> from_all = dijkstra(x, reverse_graph);

    // 왕복 시간 계산 (최댓값 찾기)
    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        int round_trip = from_all[i] + to_all[i];
        max_time = max(max_time, round_trip);
    }

    cout << max_time << "\n";

    return 0;
}
