#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals
int _root(int u, int* visit);


int main(int argc, char* argv[]) {
	int V; // 정점의 개수 V
	int E; // 간선의 개수 E
	scanf("%d %d", &V, &E); // 입력
	
	priority_queue<pair<int, pair<int, int>>> graph;
	
	int join[10000] = {0, };
	for(int i=1; i<=V; i++) {
		join[i] = i;
	} // 그룹 초기화
	
	for(int i=0; i<E; i++) {
		int u,v; // 임의의 정점 u, v
		int cost; // 가중치 cost 
		scanf("%d %d %d", &u, &v, &cost);
		
		graph.push(make_pair(-cost, make_pair(u, v)));
	} // 입력
	
	int sum = 0;
	
	while(!graph.empty()) {
		auto temp = graph.top();
		graph.pop(); // 가중치가 가장 작은 간선 pop
		
		int u = temp.second.first;
		int v = temp.second.second; // 간선으로 연결된 정점 u, v
		
		int _u = _root(u, join);
		int _v = _root(v, join); // 각 정점의 뿌리 찾기
		// printf("%d %d\n", _u, _v);
		
		if(_u==_v) {
			continue;
		} // 같은 그룹일 경우 패스
		else {
			join[_u] = join[_v] = (_u>_v)?_v:_u; // 한 그룹의 뿌리를 다른 그룹에 연결하기
			sum += temp.first;
		} // 다른 그룹일 경우 더 작은 값을 공통 뿌리로 지정 후 가중치의 합 계산
		
		// for(int i=1; i<=V; i++) {
		// 	printf("%d : %d\n", i, join[i]);
		// }
		// printf("\n");
	}
	
	printf("%d\n", -sum);
}

int _root(int u, int* visit) {
	if(*(visit+u)!=u) {
		int temp = _root(*(visit+u), visit);
		return temp;
	} // if(visit[u]!=u)
	else {
		return u;
	}
} // 그룹 확인 함수