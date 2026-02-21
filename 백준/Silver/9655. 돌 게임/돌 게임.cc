#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    // 속도 관련
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n+1, 0);

    dp[0] = n;

    int turn;
    for(turn=1; turn<=n; turn++) {
        if(dp[turn-1] >= 3) {
            dp[turn] = dp[turn-1] - 3;
        } else {
            dp[turn] = dp[turn-1] - 1;
        }

        if(dp[turn] == 0) break;
    }

    cout << ((turn % 2) ? "SK\n" : "CY\n"); 

    return 0;
}
