#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals

int main(int argc, char* argv[]) {
	int N, M;
	scanf("%d%d", &N, &M);
	
	vector<vector<int>> graph(N+1); // 그래프 인접 리스트
	int indegree[32001] = {0, }; // 진입차수, N 최대값 32000
	vector<int> order; // 순서
	
	for(int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v); // u > v 방향
		
		graph[u].push_back(v); // 인접 리스트 추가
		indegree[v]++; // 진입차수 증가
	}
	
	queue<int> q; // 위상정렬 시 사용할 큐
	
	for(int i=1; i<=N; i++) {
		if(indegree[i]==0) {
			q.push(i); // 큐 추가
			indegree[i] = -1; // 방문했다는 표시로 진입차수 -1 할당
			break; // 무조건 작은 숫자부터 입력할 수 있도록
		}
	} // 진입차수가 0인 정점을 큐에 추가
	
	while(!q.empty()) {
		int temp = q.front(); // 탐색할 정점
		q.pop(); // 큐에서 제거
		order.push_back(temp); // 순서에 추가
		
		for(auto x:graph[temp]) {
			indegree[x]--;
		} // 정점 temp와 연결된 간선 제거
		
		for(int i=1; i<=N; i++) {
			if(indegree[i]==0) {
				q.push(i); // 큐 추가
				indegree[i] = -1; // 방문했다는 표시로 진입차수 -1 할당
				break; // 무조건 작은 숫자부터 입력할 수 있도록
			}
		} // 진입차수가 0인 정점을 큐에 추가
	}
	
	for(auto x:order) {
		printf("%d ", x);
	}
}