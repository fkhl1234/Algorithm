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

vector<int> st;
int n, m;

void DFS(int start, int cnt) {
     if(cnt==0) {
          for(auto x: st) {
               printf("%d ", x);
          }
          printf("\n");

          return;
     }

     for(int i=1; i<=n; i++) {
          st.push_back(i);

          DFS(i, cnt-1);

          st.pop_back();
     }
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n >> m;
     
     DFS(1, m);

     return 0;
}
