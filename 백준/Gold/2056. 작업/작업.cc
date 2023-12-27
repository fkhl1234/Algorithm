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
	int N;
	scanf("%d", &N); // N 작업 수
	
	vector<vector<int>> graph(N+1); // DAG를 입력 받을 벡터
	vector<int> inbound[32001]; // 각 작업마다의 선행 작업을 입력 받을 벡터 배열
	int* indegree = new int[N+1]; // indegree[] 진입차수
	int* time = new int[N+1]; // time[] 작업 소요 시간 - 작업이 끝나는 시점까지 소요되는 시간
	for(int i=1; i<=N; i++) {
		int t; // t 각 작업의 시간
		int num; // num 선행 작업 수
		
		scanf("%d %d", &t, &num);
		time[i] = t; // 작업 소요 시간 기록
		for(int j=0; j<num; j++) {
			int temp;
			scanf("%d", &temp); // temp 선행 작업
			graph[temp].push_back(i); // 벡터를 이용한 그래프 작성, temp > i 방향
			inbound[i].push_back(temp); // 선행 작업 기록
		}
		indegree[i] = num; // i번째 작업의 진입차수 = 선행 작업 수
	}
	
	queue<int> q;
	q.push(1); // 위상정렬에 사용할 큐 q
	
	while(!q.empty()) {
		int pre = q.front();
		q.pop(); // pre 큐의 첫 번째 원소
		indegree[pre] = -1; // 방문했다는 표시
		
		for(auto x:graph[pre]) {
			indegree[x]--; // 연결되어 있는 간선 제거
		}
		
		for(int i=1; i<=N; i++) {
			if(indegree[i] == 0) {
				indegree[i] = -1; // 방문했다는 표시
				q.push(i); // 큐에 추가
				
				int max = 0; // 선행 작업 중 가장 오래 걸리는 작업의 시간
				for(auto x:inbound[i]) {
					if(time[x]>max) max = time[x];
				} // 가장 오래 걸리는 선행 작업 탐색
				time[i] += max; // 해당 작업을 끝내기까지 걸리는 시간
			}
		}
	} // 큐가 빌 때까지, 즉 더 이상 진입차수가 0인 작업이 없을 때까지
	
	// for(int i=1; i<=N; i++) {
	// 	printf("%d : %d\n", i, time[i]);
	// }
	
	int max = 0;
	for(int i=1; i<=N; i++) {
		if(time[i]>max) max = time[i];
	} // 소요 시간의 최대값 찾기
	printf("%d\n", max); 
	
	delete[] time;
	delete[] indegree;
}