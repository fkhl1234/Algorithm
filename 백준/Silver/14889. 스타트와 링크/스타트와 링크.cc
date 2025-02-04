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
int ability[21][21] = {0, };
int select_team[21] = {0, };

int min_diff = INT32_MAX;

void solve(int start, int cnt) {
     if(cnt==n/2) {
          vector<int> team0; // unselected
          vector<int> team1; // selected

          for(int i=1; i<=n; i++) {
               if(select_team[i]==0) team0.push_back(i);
               else team1.push_back(i); 
          }

          // for(auto x: select) cout << x << " ";
          // cout << endl;

          int team0s = 0;
          int team1s = 0;

          for(int i=0; i<n/2; i++) {
               for(int j=0; j<n/2; j++) {
                    int a = team0[i];
                    int b = team0[j];

                    int c = team1[i];
                    int d = team1[j];

                    team0s += ability[a][b];
                    team1s += ability[c][d];
               }
          }
          

          int diff = team0s > team1s ? team0s - team1s : team1s - team0s;
          if(diff<min_diff) min_diff = diff;

          return;
     }

     for(int i=start; i<=n; i++) {
          select_team[i] = 1;
          solve(i+1, cnt+1);
          select_team[i] = 0;
     }
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;

     for(int i=1; i<=n; i++) {
          for(int j=1; j<=n; j++){
               cin >> ability[i][j];
          }
     }

     solve(1, 0);

     cout << min_diff << endl;

     return 0;
}
