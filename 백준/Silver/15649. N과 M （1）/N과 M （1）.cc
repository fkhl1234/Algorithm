#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
int selected[9] = {0, };

void back_track(int cnt);

int main() {
    scanf("%d %d", &N, &M); // N : range, M : num of array

    back_track(1);
}


void back_track(int cnt) {
    if(cnt == M+1) {
        for(int i=1; i<=M+1; i++) {
            for(int j=1; j<=N; j++) {
                if(selected[j]==i) printf("%d ", j);
            }
        }
        printf("\n");
    }

    for(int i=1; i<=N; i++) {
        if(!selected[i]) {
            selected[i] = cnt;
            back_track(cnt+1);
            selected[i] = 0;
        }
    }

}