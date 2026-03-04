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

string add(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string result = "";

    while(i>=0 || j>=0 || carry) {
        int sum = carry;
        if(i>=0) sum += a[i--] - '0';
        if(j>=0) sum += b[j--] - '0';

        result += (sum % 10) + '0';

        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // 속도 관련
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> dp(n+1);

    dp[0] = "0";
    if(n>0) dp[1] = "1";

    for(int i=2; i<=n; i++) {
        dp[i] = add(dp[i-1], dp[i-2]);
    }

    cout << dp[n] << "\n";
}