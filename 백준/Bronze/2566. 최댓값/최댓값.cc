#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
     int matrix[9][9] = {0, };

     for(int i=0; i<9; i++) {
          for(int j=0;j<9;j++) {
               scanf("%d", &matrix[i][j]);
          }
     }

     int row, col, max = -1;
     for(int i=0; i<9; i++) {
          for(int j=0;j<9;j++) {
               if(matrix[i][j]>max) {
                    max = matrix[i][j];
                    row = i;
                    col= j;
               }
          }
     }

     printf("%d\n%d %d", max, row+1, col+1);
}