#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve();
// void solve(vector<int>& integer, int n);

int number[10001] = {0, };

int main() {
     int n;
     scanf("%d", &n);

     for(int i=0; i<n; i++) {
          int m;
          scanf("%d", &m);

          number[m]++;
     }
     
     solve();

     return 0;
}

void solve() {
     for(int i=0; i<10001; i++) {
          for(int j=0; j<number[i]; j++) {
               printf("%d\n", i);
          }
     }

     return;
}