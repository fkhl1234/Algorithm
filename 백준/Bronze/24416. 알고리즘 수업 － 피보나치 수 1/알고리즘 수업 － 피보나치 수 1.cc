#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int m;
int cnt1 = 0;
int cnt2 = 0;

int fib(int n) {
     if (n == 1 or n == 2) {
          cnt1++;
          return 1;
     }
     else {
          return (fib(n - 1) + fib(n - 2));
     }
}

int fibonacci(int n) {
     int f[41] = {0, };

     f[1] = 1;
     f[2] = 1;

     for(int i=3; i<=n; i++) {
          cnt2++;
          f[i] = f[i-1] + f[i-2];
     }

     return f[n];
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> m;

     int f1 = fib(m);
     int f2 = fibonacci(m);

     cout << cnt1 << " " << cnt2 << endl;

     return 0;
}
