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

    vector<int> dp(n+1, 1e9);

    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j*j<=i; j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }

    cout << dp[n] << endl;


    return 0;
}
