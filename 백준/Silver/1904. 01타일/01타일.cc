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
int memo[1000001] = {0, };

int solve(int m) {
     if(memo[m]!=0) return memo[m]%15746;

     memo[m] = (solve(m-1) + solve(m-2))%15746;

     return memo[m];
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;
     
     memo[1] = 1;
     memo[2] = 2;

     int ans = solve(n);

     cout << ans << endl;

     return 0;
}