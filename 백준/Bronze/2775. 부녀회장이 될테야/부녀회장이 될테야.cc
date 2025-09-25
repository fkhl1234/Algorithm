#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for(int t=0; t<T; t++) {
        int k, n;
        scanf("%d %d", &k, &n);

        int apt[15][14] = {0, };

        for(int i=0; i<n; i++) {
            apt[0][i] = i+1;
        }

        for(int i=1; i<=k; i++) {
            apt[i][0] = 1;
            for(int j=1; j<n; j++) {
                apt[i][j] = apt[i][j-1] + apt[i-1][j];
            }
        }

        printf("%d\n", apt[k][n-1]);
    } 
    return 0;
}