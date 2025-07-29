#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int vid[64][64];

void quarter(int n, int start_x, int start_y) {
    int crt = vid[start_x][start_y];
    bool zipped = true;

    // 범위 순회
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x = start_x + i;
            int y = start_y + j;
    
            if(vid[x][y]!=crt) {
                zipped = false;
                break;
            }
        }
        if(!zipped) break;
    }

    // 압축 가능 시 압축 or 범위 나눠 다시 재귀
    if(zipped) {
        printf("%d", crt);
    }
    else {
        printf("(");

        quarter(n/2, start_x, start_y);
        quarter(n/2, start_x, start_y+n/2);
        quarter(n/2, start_x+n/2, start_y);
        quarter(n/2, start_x+n/2, start_y+n/2);

        printf(")");
    }

    return;
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &vid[i][j]);
        }
    }

    quarter(n, 0, 0);

    return 0;
}