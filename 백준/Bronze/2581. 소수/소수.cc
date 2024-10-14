#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n, int m);


int main() {
     int n, m;
     scanf("%d %d", &n, &m);

     solve(n, m);

     return 0;
}

int Earray[10001] = {0, };

void solve(int n, int m){
     Earray[1] = 1;

     for(int i=2; i<(m+1)/2; i++) {
          for(int j=2;;j++) {
               if(i*j<=m) {
                    Earray[i*j] = 1;
               }
               else break;
          }
     }      

     vector<int> prime;
     for(int i=n; i<=m; i++) {
          if(Earray[i]==0) prime.push_back(i); 
     }

     if(prime.empty()) {
          printf("-1");
          return;
     }

     int sum = 0 ;
     for(int x: prime) {
          sum += x;
     }
     printf("%d\n%d", sum, prime[0]);
}
