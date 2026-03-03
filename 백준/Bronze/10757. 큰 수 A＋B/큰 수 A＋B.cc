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

    string a, b;
    cin >> a >> b;

    string result = add(a, b);

    cout << result << "\n";
}