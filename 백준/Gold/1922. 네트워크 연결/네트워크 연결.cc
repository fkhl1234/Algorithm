#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals
struct pair_cmd {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int main(int argc, char* argv[]) {
	int N; // 컴퓨터 수
	scanf("%d", &N);
	
	int M; // 회선 수
	scanf("%d", &M);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmd> graph[1001]; // 각 회선의 코스트를 기록할 벡터
	for(int i=0; i<M; i++) {
		int u, v; // 연결된 간선 2개
		int cost; // 간선의 비용
		
		scanf("%d %d %d", &u, &v, &cost);
		graph[u].push(make_pair(v, cost));
		graph[v].push(make_pair(u, cost)); // 회선의 반대쪽 정점과 비용을 pair로 추가
	}
	
	vector<int> MST; // MST를 기록할 스택
	bool visit[1001] = {0, }; // 정점을 방문했는지 체크할 배열
	int cost = 0; // 최소 비용
	
	MST.push_back(1); // 1번 정점부터 탐색 시작
	visit[1] = true; // 방문 표시
	
	for(int i=0; i<N-1; i++) {
		int min = 10001; // 가중치의 최솟값
		int v; // 가중치가 가장 작은 간선으로 연결되어 있는 정점 v
		for(auto x:MST) {
			while(!graph[x].empty() && visit[graph[x].top().first]) {
				graph[x].pop();
			} // 방문하지 않은 정점 탐색
			
			if(min>graph[x].top().second && !graph[x].empty()) {
				min = graph[x].top().second;
				v = graph[x].top().first;
			} // 가중치가 가장 작은 간선 탐색
		} // MST에 들어있는 모든 정점과 연결되어 있는 간선 탐색
		
		cost += min; // 최소 가중치 추가
		MST.push_back(v); // MST에 정점 v 추가 (가중치가 가장 작은 간선으로 연결되어 있는 정점)
		visit[v] = true; // 정점 v 방문 표시
	} // MST의 간선 개수는 언제나 N-1개 
	
	printf("%d", cost);
}