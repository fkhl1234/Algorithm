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
long long int memo[101] = {0, };

long long int solve(int m) {
     if(memo[m]!=0) return memo[m];

     memo[m] = solve(m-2) + solve(m-3);

     return memo[m];
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     int T;
     cin >> T;
     
     memo[1] = 1;
     memo[2] = 1;
     memo[3] = 1;

     for(int i=0; i<T; i++) {
          cin >> n;
          long long int ans = solve(n);
          cout << ans << endl;
     }


     return 0;
}