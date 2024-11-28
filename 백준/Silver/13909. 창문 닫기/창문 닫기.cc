#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
     long long int n;
     scanf("%lld", &n);

     int cnt = 0;
     for(long long int i=1; i*i<=n; i++) {
          cnt++;
     }

     printf("%d\n", cnt);

     return 0;
}