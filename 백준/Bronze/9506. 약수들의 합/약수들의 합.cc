#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n);


int main() {
     int n;
     while(1){
          scanf("%d", &n);

          if(n<0) return 0;

          solve(n);
     }

     return 0;
}

void solve(int n){
     vector<int> divisor;

     for(int i=1; i<n; i++) {
          if(n%i==0) divisor.push_back(i);
     }

     int sum = 0;
     for(int x: divisor) {
          sum += x;
     }

     if(n==sum) {
          printf("%d = ", n);

          for(vector<int>::iterator iter = divisor.begin(); iter!=divisor.end(); iter++) {
               if(iter!=divisor.end()-1) {
                    printf("%d + ", *iter);
               }
               else printf("%d\n", *iter);
          }
     }
     else printf("%d is NOT perfect.\n", n);

     // printf("%d\n", sum);
}
