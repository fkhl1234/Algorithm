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
	int M, N;
	scanf("%d %d", &M, &N);
	
	int box[1002][1002];
	for(int i=0; i<=1001; i++) {
		for(int j=0; j<=1001; j++) {
			box[i][j] = -1;
		}
	}
	
	bool visit[1001][1001] = {0, };
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%d", &box[i][j]);
		}
	}	
	
	queue<pair<int,int>> BFS;
	int day = 0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(box[i][j]==1) {
				visit[i][j] = true;
				BFS.push(make_pair(i, j));
			} // 방문하지 않은 토메이로가 있을 때
		}
	} // 초기 토메이로 찾기
	
	while(!BFS.empty()) {
		int size = BFS.size();
		for(int a=0; a<size; a++) {
			int i = BFS.front().first;
			int j = BFS.front().second;
			BFS.pop();
			
			for(int b=0; b<4; b++) {
				int nj = (j+dx[b]);
				int ni = (i+dy[b]);
				
				if(box[ni][nj]==0) {
					box[ni][nj] = 1;
					visit[ni][nj] = true;
 					BFS.push(make_pair(ni, nj));
				}
			}
		}
		day++;
	}
	
	bool check=true;
	
	for(int i=1;i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(box[i][j] == 0) {check = false; break;}
		}
	}
	
	day--;
	printf("%d\n", check ? day : -1);
}