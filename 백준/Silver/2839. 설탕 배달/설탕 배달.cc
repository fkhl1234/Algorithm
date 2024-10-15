#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n);


int main() {
     int n;
     scanf("%d", &n);
     
     solve(n);

     return 0;
}

void solve(int n) {
     int max3 = n/3;
     int max5 = n/5;

     for(int i=max5; i>=0; i--) {
          for(int j=0; i*5+j*3<=n; j++) {
               if(i*5+j*3==n) {
                    printf("%d", i+j);
                    return;
               }
          }
     }

     printf("-1\n");
     return;
}