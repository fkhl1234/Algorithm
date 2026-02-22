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

    int n, k;
    cin >> n >> k;

    vector<int> dp(k+1, 0);
    for(int i=0; i<n; i++) {
        int weight, v;
        cin >> weight >> v;

        for(int w=k; w>=weight; w--) {
            dp[w] = max(dp[w], dp[w-weight] + v);
        }
    }

    cout << dp[k] << "\n";
}