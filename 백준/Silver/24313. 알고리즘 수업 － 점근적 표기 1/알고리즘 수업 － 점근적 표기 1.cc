#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int a1, int a0, int c, int n0);


int main() {
     int x, y, w, h;

     scanf("%d %d %d %d", &x, &y, &w, &h);
     
     solve(x, y, w, h);

     return 0;
}

void solve(int a1, int a0, int c, int n0) {
     // x X+ y < w X (x>=h)
     // y/(w-x) < X
     // y/(w-x) < h  비교
     // y < h(w-x)

     if(c-a1>0) {
          if(a0<=n0*(c-a1)) {
               printf("1\n");
          }
          else printf("0\n");
     }
     else if(c-a1==0) {
          if(a0<=0) printf("1\n");
          else printf("0\n");
     }
     else {
          printf("0\n");
     }
}