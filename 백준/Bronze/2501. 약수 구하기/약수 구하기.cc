#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
     int n, k;
     scanf("%d %d", &n, &k);

     int cnt = 0;
     int i;
     for(i=1; cnt<k; i++) {
          if(n%i==0) cnt++;
          if(i>n) {
               printf("0\n");
               return 0;
          }
     }

     printf("%d\n", --i);

     return 0;
}