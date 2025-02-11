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
long long int memo[10] = {0, };

void solve() {
     long long int temp[10] = {0, };
     temp[0] = memo[1] % 1000000000;;
     for(int i=1; i<9; i++) {
          temp[i] = (memo[i-1] + memo[i+1]) % 1000000000;
     }
     temp[9] = memo[8] % 1000000000;;

     copy(temp, temp+10, memo);
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;
     for(int i=1; i<10; i++) {
          memo[i] = 1;
     }

     for(int i=1; i<n; i++) {
          solve();
     }

     int ans = 0;
     for(auto x: memo) {
          ans =  (ans + x) % 1000000000;;
     }

     cout << ans << endl;

     return 0;
}