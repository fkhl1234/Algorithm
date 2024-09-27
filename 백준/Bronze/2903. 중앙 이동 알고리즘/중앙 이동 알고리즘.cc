#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
     int n;
     scanf("%d", &n);

     long long unsigned int sq = 1;
     for(int i=0; i<n; i++) {
          sq *= 2;
     }

     printf("%lld\n", (sq+1)*(sq+1));
}