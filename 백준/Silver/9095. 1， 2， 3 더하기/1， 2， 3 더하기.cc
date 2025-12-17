#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for(int tcase=0; tcase<T; tcase++) {
        int n = 0;
        scanf("%d", &n);
    
        int dp[20] = {0, };
    
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4; // 1 + 1 + 1 = 2 + 1 = 1 + 2 = 3
    
        for(int i=4; i<=n; i++) {
            dp[i] = dp[i-3] + dp[i-2] + dp [i-1];
        }
    
        printf("%d\n", dp[n]);
    }

    return 0;
}
