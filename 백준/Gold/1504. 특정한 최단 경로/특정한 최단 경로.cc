#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

#define INF 2147483647

using namespace std;

//Globals
void input();
void solve();

int N, M;
vector<pair<int, int>> graph[1001];
vector<long long int> dist(1002, INF);
bool visit[1001] = {0, };
int v1, v2;

int main(int argc, char* argv[]) {
	input();
	solve();
}

void input() {
	scanf("%d", &N); // 도시 개수
	scanf("%d", &M); // 도로 개수
	
	for(int i=0; i<M; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c); // 도로 정보 입력
		
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c)); // 그래프 구성
	}
	
	scanf("%d %d", &v1, &v2); // 경유지점1 경유지점2
}

void solve() {	
	int start[3] = {1, v1, v2};
	
	int min = 1001;// 방문하지 않는 정점 중 dist 값이 가장 작은 정점
	dist[min] = INF; // 가장 긴 거리 설정
	
	long long int cost[2] = {0, };
	
	for(int a=0; a<3; a++) {
		dist[start[a]] = 0; // 시작점과의 거리는 0
		
		for(int b=1; b<=N; b++) {
			min = 1001;
			for(int i=1; i<=N; i++) {
				if(!visit[i] && dist[i]<=dist[min]) {
					min = i; // 시작점과 가장 가까운 정점 갱신
				} // 아직 방문하지 않았고 시작점으로부터 거리가 가장 작을 때
			} // 모든 정점에 대해
			
			visit[min] = true; // 방문 표시
			
			for(auto x:graph[min]) {
				int v = x.first; // 반대편 정점
				int c = x.second; // 거리
				
				if(dist[v]>dist[min]+c) {
					dist[v] = dist[min]+c; // 최단거리 갱신
				} // 정점 min을 거친 경로가 더 짧을 때
			} // 정점 min과 연결된 모든 간선에 대해
			
		} // 모든 정점을 방문할 때까지 : 언제나 다른 정점을 방문하므로 N번의 방문이면 모든 정점을 방문
		
		if(dist[v1]==INF || dist[v2]==INF || dist[N]==INF) {
			printf("-1\n");
			return;
		}
		
		if(a==0) {
			cost[0] += dist[v1];
			cost[1] += dist[v2];
		} 
		else if(a==1) {
			cost[0] += dist[v2];
			cost[1] += dist[N];
		}
		else {
			cost[0] += dist[N];
			cost[1] += dist[v1];
		}
		/*
			경로1, cost[0]
			: 1 > v1 > v2 > N
			
			경로2, cost[1]
			: 1 > v2 > v1 > N
		*/
		
		for(int i=1; i<=N; i++) {
			dist[i] = INF;
			visit[i] = false;
		} // 최단거리, 방문여부 초기화
	}
	
	printf("%lld\n", cost[0]>cost[1] ? cost[1] : cost[0]);
}