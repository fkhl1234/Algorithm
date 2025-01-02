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

void onethird(int x_start, int x_end, int y_start, int y_end);
int arr[6562][6562] = {0, };

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     int n;
     scanf("%d", &n);

     onethird(1, n, 1, n);

     for(int i=1; i<=n; i++) {
          for(int j=1; j<=n; j++) {
               if(arr[i][j]) printf(" ");
               else printf("*");
          }
          printf("\n");
     }
}

void onethird(int x_start, int x_end, int y_start, int y_end) {
     int len = x_end-x_start+1;
     if(len>=3) {
          int x_mid = x_start+(len/3);
          int y_mid = y_start+(len/3);

          for(int i=0; i<len/3; i++) {
               for(int j=0; j<len/3; j++) {
                    arr[y_mid+i][x_mid+j] = 1;
               }
          }

          int x_coord[] = {x_start, x_mid, x_end-len/3+1, x_end+1};
          int y_coord[] = {y_start, y_mid, y_end-len/3+1, y_end+1};
          for(int i=0; i<3; i++) {
               for(int j=0; j<3; j++) {
                    onethird(x_coord[i], x_coord[i+1]-1, y_coord[j], y_coord[j+1]-1);
               }
          }

     }
}