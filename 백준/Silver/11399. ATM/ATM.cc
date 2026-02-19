#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int cost[1001] = {0, };
    for(int i=0; i<n; i++) {
        scanf("%d", &cost[i]);
    }

    sort(cost, cost+n);

    int total_cost = 0;
    for(int i=0; i<n; i++) {
        // printf("%d ", cost[i]);
        total_cost += cost[i] * (n-i);
    }

    printf("%d\n", total_cost);

    return 0;
}