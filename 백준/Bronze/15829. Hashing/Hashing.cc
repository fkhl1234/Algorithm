#include <stdio.h>
#define MaxLen 50

int main() {
    int n;
    char string[MaxLen+1];

    scanf("%d", &n);
    scanf("%s", string);

    const int r = 31;
    const int M = 1234567891;

    long long hash_res = 0;
    long long cardi = 1;
    for(int i=0; i<n; i++) {
        int c = string[i] - 'a' + 1;
        hash_res += c * cardi;
        cardi = ((cardi % M) * 31) % M;
    }

    printf("%lld", hash_res);
    
    return 0;
}