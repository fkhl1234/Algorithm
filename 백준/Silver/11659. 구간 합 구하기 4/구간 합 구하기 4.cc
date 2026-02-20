#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int sum[100001];

int main() {
    // 속도 관련
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    sum[0] = 0;
    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        sum[i] = tmp + sum[i-1];
    }

    for(int i=0; i<m; i++) {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start-1] << "\n";
    }

    return 0;
}