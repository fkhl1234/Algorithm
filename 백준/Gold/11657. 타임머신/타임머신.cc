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
vector<pair<int, int>> graph[501];
vector<long long int> D(501, INF);

void bf(int N);
bool bf_check(int N);
	
int main(int argc, char* argv[]) {
	int N, M;
	scanf("%d %d", &N, &M); // N 도시의 개수 M 버스의 개수
	
	for(int i=0; i<M; i++) {
		int u, v, c;
		scanf("%d%d%d",&u,&v,&c);
		
		graph[u].push_back(make_pair(v, c));
	} // 방향 그래프인 것을 유의하며 입력
	
	D[1] = 0; // 시작점까지의 거리는 언제나 0
	
	for(int i=0; i<N-1; i++) {
		bf(N);
	} // N-1번 탐색
	
	bool check = bf_check(N);
	
	if(!check) return 0;
	
	for(int i=2; i<=N; i++) {
		printf("%lld\n", (D[i]==INF)?-1:D[i]);
	}
	
}

void bf(int N) {
	for(int i=1; i<=N; i++) {
		if(D[i]!=INF) {
			for(auto x:graph[i]) {
				int u = x.first; // 간선의 목적지
				int c = x.second; // 간선의 가중치
				
				D[u] = (D[i]+c>D[u]) ? D[u] : D[i]+c; // "정점 i를 거쳐서 가는 길"과 "지금까지 찾아낸 최단경로" 중 더 작은 경로가 최단경로
			}
		} // 거리가 INF가 아닐 경우, 즉 한 번이라도 탐색한 정점일 경우
	}
}

bool bf_check(int N) {
	for(int i=1; i<=N; i++) {
		for(auto x:graph[i]) {
			int u = x.first; // 간선의 목적지
			int c = x.second; // 간선의 가중치
			
			if(D[i]+c<D[u] && D[i]!=INF) {
				printf("-1\n");
				return false;
			} // 만약 N-1번 이상 반복해도 거리가 계속 줄어든다면 음의 사이클이 존재
		}
	}
	
	return true;
}