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

int sudoku[9][9] = {0, };

bool isSafe(int x, int y) {
     int value = sudoku[y][x];
     sudoku[y][x] = -1;
     
     for(int i=0; i<9; i++) {
          if(sudoku[y][i]==value || sudoku[i][x]==value) {
               sudoku[y][x] = value;
               return false;
          } 
     }
     // row/col check

     int xs = x/3;
     int ys = y/3;

     for(int i=0; i<3; i++) {
          for(int j=0; j<3; j++) {
               if(sudoku[3*ys+i][3*xs+j]==value) {
                    sudoku[y][x] = value;
                    return false;
               }
          }
     }
     // square check

     sudoku[y][x] = value;

     return true;
}

vector<pair<int, int>> blank;
bool fin = false;

void solve(int cnt) {
     if(cnt==blank.size()) {
          fin = true;
          return;
     }

     int x = blank[cnt].first;
     int y = blank[cnt].second;
     
     for(int i=1; i<=9 ; i++) {
          sudoku[y][x] = i;
          if(isSafe(x, y)) {
               solve(cnt+1);
          }

          if(fin) return;
     }

     sudoku[y][x] = 0;
     return;
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     for(int i=0; i<9; i++) {
          for(int j=0; j<9; j++) {
               scanf("%d", &sudoku[i][j]);
          }
     }

     for(int i=0; i<9; i++) {
          for(int j=0; j<9; j++) {
               if(sudoku[i][j]==0) {
                    blank.push_back(make_pair(j, i));
               }
          }
     }     

     // for(auto x: blank) {
     //      cout << x.first << " " << x.second << endl;
     // }
     // cout << blank.size() << endl;

     solve(0);

     // sudoku print
     for(int i=0; i<9; i++) {
          for(int j=0; j<9; j++) {
               printf("%d ", sudoku[i][j]);
          }
          printf("\n");
     }
     
     // auto check = isSafe(2, 0);

     // cout << check << endl;

     return 0;
}
