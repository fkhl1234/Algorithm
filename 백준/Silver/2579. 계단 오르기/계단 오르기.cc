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
int stair[300] = {0, };
int memo[300] = {0, };

void solve() {
     for(int i=3; i<n; i++) {
          memo[i] = max(memo[i-3]+stair[i-1]+stair[i], memo[i-2]+stair[i]);
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
          cin >> stair[i];
     }

     memo[0] = stair[0];
     memo[1] = stair[0]+stair[1];
     memo[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

     solve();

     cout << memo[n-1] << endl;

     return 0;
}