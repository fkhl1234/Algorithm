#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
     char matrix[5][16] = {0, };

     for(int i=0; i<5; i++) {
          scanf("%s", matrix[i]);
     }

     for(int i=0; i<15; i++) {
          for(int j=0;j<5;j++) {
               if(matrix[j][i] != '\0')  printf("%c", matrix[j][i]);
          }
     }
}