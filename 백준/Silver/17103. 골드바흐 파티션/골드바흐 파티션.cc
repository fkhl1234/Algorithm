#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool isPrime(long long n);

int range = 0;
bool prime[1000001] = {0, };

int main() {
     int T;
     scanf("%d", &T);

     for(int j=0; j<T; j++) {
          int n;
          scanf("%d", &n);

          if(range<n) {
               for(int i=range+1; i<=n; i++) {
                    prime[i] = isPrime(i);
               }
               range = n;
          }

          int cnt = 0;
          for(int i=2; i<=n/2; i++) {
               if(prime[i] && prime[n-i]) cnt++;
          }

          printf("%d\n", cnt);
     }
     return 0;
}

bool isPrime(long long n) {
     if(n<4) {
          if(n<=1) return false;
          else return true;
     }

     if(n%2==0) return false;
     for(long long int i=3; i*i<=n; i+=2) {
          if(n%i==0) return false;
     }

     return true;
}