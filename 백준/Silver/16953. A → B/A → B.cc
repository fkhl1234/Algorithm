#include <stdio.h>

int A, B;

int trans(int n, int dep) {
    if(n==A) return dep;
    else if(n==1) return -1;

    int digit = n % 10;
    
    if(digit==1) {
        int ret = trans(n/10, dep+1);
        return ret;
    } else if(digit % 2 == 1 ) {
        return -1;
    }

    int ret = trans(n/2, dep+1);
    return ret;
}


int main() {
    scanf("%d %d", &A, &B);

    int ret = trans(B, 1);

    printf("%d\n", ret);
    return 0;
}