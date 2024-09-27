#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
     int n;
     scanf("%d", &n);
     
     int cnt = 1;
     int index = 2;
     for(int i=1; i<n ;i++) {
          n -= i;
          index++;
     }

     if(index%2!=0) printf("%d/%d", n, index-n);
     else printf("%d/%d", index-n, n);
}