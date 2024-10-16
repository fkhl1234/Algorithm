#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// void solve(int n);
void solve(vector<int>& integer, int n);


int main() {
     int n, k;
     scanf("%d", &n);

     vector<int> integer;
     for(int i=0; i<n; i++) {
          int m;
          scanf("%d", &m);

          integer.push_back(m);
     }
     
     solve(integer, n);

     return 0;
}

void solve(vector<int>& integer, int n) {
     sort(integer.begin(), integer.end());

     for(auto x: integer) {
          printf("%d\n", x);
     }

     return;
}