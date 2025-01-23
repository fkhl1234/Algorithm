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
int chessboard[16] = {0, };
int cnt = 0;

bool isSafe(int x, int y) {
     for(int i=1; i<y; i++) {
          if(chessboard[i] == x) return false;
          if((chessboard[i]-x)==(y-i) || (chessboard[i]-x)==(i-y)) return false;
     }

     return true;
}

void nQueen(int queen) {
     if(queen>n) {
          cnt++;
          return;
     }
     
     for(int i=1; i<=n; i++) {
          if(isSafe(i, queen)) {
               chessboard[queen] = i;
               nQueen(queen+1);
               chessboard[queen] = 0; 
          }
     }

     return;
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;

     nQueen(1);

     printf("%d\n", cnt);

     return 0;
}
