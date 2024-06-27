#include <iostream>
#include <cstdio>

using namespace std;

int ground[52][52] = {0, }; // ground array : for exception handling
bool visit[51][51] ={0, }; //visit check

void DFS(int x, int y); // cabbage search

int main() {
    int T; //test case
    int N, M; // width - height
    int num; // number of cabbage
    scanf("%d", &T);

    for(int t=0; t<T; t++) {
        scanf("%d %d %d", &M, &N, &num); // input x, y, num

        for(int i=0; i<num; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            ground[y+1][x+1] = 1; // cabbage location mark
        }

        int cnt = 0; // count for cabbage island

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M ;j++) {
                if(ground[i][j] && !visit[i][j]) {
                    DFS(j, i);
                    cnt++;
                    //printf("%d %d\n", i, j);
                }
            }
        } // check all ground

        printf("%d\n", cnt);

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                ground[i][j] = 0;
                visit[i][j] = false;
            }
        } // reset all relevant array
    }
    return 0;
}

void DFS(int x, int y) {
    if(!visit[y][x]) {
        visit[y][x] = true; // visit check

        if(ground[y-1][x] && !visit[y-1][x]) {
            DFS(x, y-1);
        }

        if(ground[y+1][x] && !visit[y+1][x]) {
            DFS(x, y+1);
        }

        if(ground[y][x+1] && !visit[y][x+1]) {
            DFS(x+1, y);
        }

        if(ground[y][x-1] && !visit[y][x-1]) {
            DFS(x-1, y);
        }
    } // in case this location not visited
}

