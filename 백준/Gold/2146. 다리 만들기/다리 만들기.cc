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
	scanf("%d", &N);
	
	int map[102][102] = {0, };
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	queue<pair<int, int>> BFS;
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	int island_num = 0;
	bool visit[102][102] = {0, };
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(map[i][j] == 1 && !visit[i][j]) {
				island_num++;
				map[i][j] = island_num;
				BFS.push(make_pair(i, j));
				
				while(!BFS.empty()) {
					int x = BFS.front().first;
					int y = BFS.front().second;
					BFS.pop();
					
					for(int j=0; j<4; j++) {
						int nx = x + dx[j];
						int ny = y + dy[j];
						
						if(map[nx][ny] == 1 && !visit[nx][ny]) {
							map[nx][ny] = island_num;
							visit[nx][ny] = true;
							BFS.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(map[i][j] != 0) {
				BFS.push(make_pair(i, j));
			}
		}
	} // 땅의 좌표 모두 저장
	
	int degree = 0;
	bool integrity = true;
	int min = 98765321;
	int dis[102][102] = {0, };
	
	while(integrity) {
		int size = BFS.size();
		
		for(int i=0; i<size; i++) {
			int x = BFS.front().first;
			int y = BFS.front().second;
			BFS.pop();
			
			dis[x][y] = degree;
			
			for(int j=0; j<4; j++) {
				int nx = x + dx[j];
				if(nx>100) nx = 100;
				else if(nx<1) nx = 1;
				int ny = y + dy[j];
				if(ny>100) ny = 100;
				else if(ny<1) ny = 1;
				
				if(map[nx][ny] == 0) {
					map[nx][ny] = map[x][y];
					dis[nx][ny] = dis[x][y] + 1;
					BFS.push(make_pair(nx, ny));
				}
				else if(map[nx][ny] != map[x][y]) {
					int temp = dis[nx][ny] + dis[x][y];
					
					if(temp<min) min = temp;
					
					integrity = false;
				}
			}
		}
		
		// printf("\n");
		// for(int i=1; i<=N; i++) {
		// 	for(int j=1 ;j<=N; j++) {
		// 		printf("%d ", dis[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		
		degree++;
		
	} // 땅을 점차 확장하면서 최초로 만날 때까지 반복, 만났을 때의 degree가 거리를 나타낼 수 있다. (2*degree-1)
	
	printf("%d\n", min);
}