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

int main() {
     int T;
     scanf("%d", &T);

     for(int i=0; i<T; i++) {
          long long n;
          scanf("%lld", &n);

          long long prime;
          for(prime=n; isPrime(prime)==false; prime++) {}

          printf("%lld\n", prime);
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