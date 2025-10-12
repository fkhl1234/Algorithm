#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int coin[10] = {0, };

    for(int i=0; i<n; i++) {
        scanf("%d", &coin[i]);
    }
    n--; // coin[n] : 가장 값이 큰 코인

    int cnt = 0; // 카운트
    while(k>0) {
        if(k >= coin[n]) {
            k -= coin[n]; // 값 차감하기
            cnt++; // 카운터
        } else {
            if(n>0) {
                n--; // 다음 코인
            } else {
                continue; // 가장 작은 단위 반복
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}

/*
310
1 5 10 100 200

4 4 : 200 < 310
3 4 : 300 < 310
2 4 : 310 = 310

110
4 4 : 200 > 110
3 3 : 100 < 110
2 3 : 110 = 110
*/