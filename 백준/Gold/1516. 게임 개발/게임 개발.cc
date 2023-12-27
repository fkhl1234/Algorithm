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
	vector<int> inbound[32001]; // 각 건물마다의 선행 건물을 입력 받을 벡터 배열
	int* indegree = new int[N+1]; // indegree[] 진입차수
	int* time = new int[N+1]; // time[] 건축 소요 시간 - 건축이 끝나는 시점까지 소요되는 시간
	for(int i=1; i<=N; i++) {
		int t; // t 각 건축의 시간
		
		scanf("%d", &t);
		time[i] = t; // 건축 소요 시간 기록
		while(1) {
			int temp;
			scanf("%d", &temp); // temp 선행 건물
			if(temp==-1) break;
			graph[temp].push_back(i); // 벡터를 이용한 그래프 작성, temp > i 방향
			inbound[i].push_back(temp); // 선행 건물 기록
		} // -1이 입력될 때까지 반복
		indegree[i] = inbound[i].size(); // i번째 작업의 진입차수 = 선행 작업 수
	}
	
	queue<int> q;
	
	for(int i=1; i<=N; i++) {
		if(indegree[i]==0) {
			q.push(i); // 큐에 추가
			indegree[i] = -1; // 건설했다는 표시
		} // 바로 세울 수 있는 건물 탐색
	}
	
	while(!q.empty()) {
		int pre = q.front();
		q.pop(); // pre 큐의 첫 번째 원소
		indegree[pre] = -1; // 건설했다는 표시
		
		for(auto x:graph[pre]) {
			indegree[x]--; // 연결되어 있는 간선 제거
		}
		
		for(int i=1; i<=N; i++) {
			if(indegree[i] == 0) {
				indegree[i] = -1; // 건설했다는 표시
				q.push(i); // 큐에 추가
				
				int max = 0; // 선행 건설 중 가장 오래 걸리는 건설의 시간
				for(auto x:inbound[i]) {
					if(time[x]>max) max = time[x];
				} // 가장 오래 걸리는 선행 건물 탐색
				time[i] += max; // 해당 건축을 끝내기까지 걸리는 시간
			}
		} // 건축 가능한 건물 건축 시간 계산
	} // 큐가 빌 때까지, 즉 더 이상 진입차수가 0인 건물이 없을 때까지
	
	for(int i=1; i<=N; i++) {
		printf("%d\n", time[i]);
	}
	
	delete[] time;
	delete[] indegree;
}