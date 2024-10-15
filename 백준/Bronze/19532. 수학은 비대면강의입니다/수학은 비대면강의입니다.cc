#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& matrix);


int main() {
     int n;

     vector<int> matrix;
     for(int i=0; i<6; i++) {
          int temp;
          scanf("%d", &temp);

          matrix.push_back(temp);
     }
     
     solve(matrix);

     return 0;
}

void solve(vector<int>& matrix) {
     for(int i=-999; i<=999; i++) {
          for(int j=-999; j<=999; j++) {
               if(matrix[0]*i + matrix[1]*j == matrix[2]) {
                    if(matrix[3]*i + matrix[4]*j == matrix[5]) {
                         printf("%d %d", i, j);
                         return;
                    }
               }
          }
     }
}