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
	scanf("%d %d", &N, &M);
	
	int map[102][102] = {0, };
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	int dis = 1;
	queue<pair<int, int>> BFS;
	BFS.push(make_pair(1, 1));
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	while(!BFS.empty()) {
		int x = BFS.front().first;
		int y = BFS.front().second;
		BFS.pop();
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(map[nx][ny] == 1) {
				map[nx][ny] = map[x][y] + 1;
				BFS.push(make_pair(nx, ny));
			}
		}
	}
	
	printf("%d\n", map[N][M]);
}