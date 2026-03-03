#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
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

    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        dp[i] = ~dp[i-1];
    }

    cout << (dp[n] == 1 ? "SK" : "CY") << "\n";
}