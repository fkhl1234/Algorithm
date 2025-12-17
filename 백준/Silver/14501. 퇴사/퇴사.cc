#include <stdio.h>

int delay[16] = {0, };
int cost[16] = {0, };

int N;

int main() {
    scanf("%d", &N);

    for(int i=1; i<=N; i++) {
        scanf("%d %d", &delay[i], &cost[i]);
    }

    int dp[17] = {0, };

    for(int i=N; i>=1; i--) {
        if(i+delay[i]-1 <= N) {
            dp[i] = (cost[i] + dp[i+delay[i]] > dp[i+1]) ?  cost[i] + dp[i+delay[i]] : dp[i+1];
        } else {
            dp[i] = dp[i+1];
        }
    }

    printf("%d\n", dp[1]);

    return 0;
}