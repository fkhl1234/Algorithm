#include <stdio.h>

int main() {
    char isbn[14];
    int idx = -1;
    for(int i=0; i<13; i++) {
        scanf("%c", &isbn[i]);
        if(isbn[i]=='*') idx = i;
    }
    
    int sum = 0;
    for(int i=0; i<12; i++) {
        if(i==idx) continue;

        int coef = (i%2) * 2 + 1;
        sum += coef * (isbn[i] - '0');
    }
    
    int m = isbn[12] - '0';
    int coef = (idx%2) * 2 + 1;
    for(int i=0; i<10; i++) {
        int cal = sum + coef * i;
        if((10 - (cal % 10)) % 10 == m) {
            m = i;
            break;
        }
    }

    printf("%d\n", m);

    return 0;
}

// 016819832*140
// 0 3 6 24 1 27 8 9 2  1 12
// 9 33 34 61 69 78 80 81 93