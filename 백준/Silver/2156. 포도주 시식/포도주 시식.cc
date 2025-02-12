#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int n;
int wine[10000] = {0, };
int memo[10000] = {0, };

void solve() {
     memo[0] = wine[0];
     memo[1] = wine[1]+wine[0];
     memo[2] = max(wine[2]+wine[0], wine[2]+wine[1]);
     memo[2] = max(memo[2], memo[1]);

     for(int i=3; i<n; i++) {
          memo[i] = max(wine[i]+wine[i-1]+memo[i-3], wine[i]+memo[i-2]);
          memo[i] = max(memo[i], memo[i-1]);
     }
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;
     for(int i=0; i<n; i++) {
          cin >> wine[i];
     }
     
     solve();

     cout << memo[n-1] << endl;

     return 0;
}