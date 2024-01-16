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
vector<long long int> dist(1002, INF-1);
bool visit[1001] = {0, };
int start, dest;

bool all_check();

int pre[1001] = {0, }; // 이전 정점
stack<int> route; // 경로 스택
void routing(int num); // 경로 찾기 함수

int main(int argc, char* argv[]) {
	input();
	
	solve();
	
	printf("%lld\n", dist[dest]);
	printf("%ld\n", route.size());
	
	while(!route.empty()) {
		int temp = route.top();
		printf("%d ", temp);
		route.pop();
	} // 경로 출력
	printf("\n");
}

void input() {
	scanf("%d", &N); // 도시 개수
	scanf("%d", &M); // 도로 개수
	
	for(int i=0; i<M; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c); // 도로 정보 입력
		
		graph[u].push_back(make_pair(v, c)); // 그래프 구성
	}
	
	scanf("%d %d", &start, &dest); // 시작지점과 도착지
	dist[start] = 0; // 시작지점과의 거리는 언제나 0
}

void solve() {	
	while(all_check() == false) {
		int min = 1001; // 방문하지 않는 정점 중 dist 값이 가장 작은 정점
		dist[min] = INF; // 가장 긴 거리 설정
		
		for(int i=1; i<=N; i++) {
			if(!visit[i] && dist[i]<dist[min]) {
				min = i;
			} // 방문하지 않은 정점 중 dist 값이 가장 작은 정점 min
		}
		
		visit[min] = true; // 정점 min 방문 체크
		
		for(auto x:graph[min]) {
			int v = x.first; // 간선의 반대편 정점
			int c = x.second; // 간선의 비용
			
			if(dist[v]>dist[min]+c) {
				dist[v] = dist[min]+c; // 최단비용 갱신
				pre[v] = min; // 이전 정점 갱신
			} // 최소비용을 갱신할 때
		} // 정점 min과 연결되어 있는 모든 간선에 대해
		
	} // 모든 정점을 방문할 때까지
	
	routing(dest); // 경로 추적
}

bool all_check() {
	for(int i=1; i<=N; i++) {
		if(!visit[i]) {
			return false;
		} // 방문하지 않은 정점이 존재할 경우 false
	}
	
	return true; // 모든 정점을 방문했을 경우 true
}

void routing(int num) {
	if(pre[num]==0) {
		route.push(num);
		return;
	} // num번 도시가 시작지점이라면
	else {
		route.push(num);
		routing(pre[num]);
	} // num번 도시가 중간지점이라면
	return;
} // num : 도착지점