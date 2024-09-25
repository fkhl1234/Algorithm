#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
     char matrix[101][101] = {0, };

     int num;
     scanf("%d",&num);


     int start_x = 100, start_y = 100;
     int end_x = 0, end_y = 0;
     for(int i=0; i<num; i++) {
          int x, y;
          scanf("%d %d", &x, &y);

          for(int i=0; i<10; i++) {
               for(int j=0; j<10; j++) {
                    matrix[x+i][y+j]++;
               }
          }

          start_x = (x<start_x) ? x : start_x;
          start_y = (y<start_y) ? y : start_y;

          end_x = (end_x<x) ? x : end_x;
          end_y = (end_y<y) ? y : end_y;
     }
     end_x += 10;
     end_y += 10;
     
     int cnt = 0;
     for(int i=start_x; i<end_x; i++) {
          for(int j=start_y; j<end_y; j++){
               if(matrix[i][j]!=0) cnt++;
          }
     }
     
     printf("%d", cnt);
}