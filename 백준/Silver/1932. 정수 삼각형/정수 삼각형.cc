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
int tri[501][502] = {0, };

void solve() {
     for(int i=2; i<=n; i++) {
          for(int j=1; j<=i; j++) {
               tri[i][j] = tri[i][j]+tri[i-1][j-1] > tri[i][j]+tri[i-1][j] ? tri[i][j]+tri[i-1][j-1] : tri[i][j]+tri[i-1][j];
          }
     }
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;
     int temp;
     for(int i=1; i<=n; i++) {
          for(int j=1; j<=i; j++) {
               cin >> tri[i][j];
          }
     }

     solve();
     
     sort(tri[n], tri[n]+n+2);

     cout << tri[n][n+1] << endl;

     return 0;
}