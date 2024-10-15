#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n);
int divided_sum(int n);


int main() {
     int n;

     scanf("%d", &n);
     
     solve(n);

     return 0;
}

void solve(int n) {
     for(int i=n-54; i<=n; i++) {
          if(divided_sum(i)==n) {
               printf("%d\n", i);
               return;
          }
     }
     printf("0\n");
}

int divided_sum(int n) {
     int sum = n;

     for(; n>0; n/=10) {
          sum += n%10;
     }

     return sum;
}