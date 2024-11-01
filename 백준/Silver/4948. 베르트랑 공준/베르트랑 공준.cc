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

     for(int i=0; ; i++) {
          int n;
          scanf("%d", &n);

          if(n==0) break;

          int cnt = 0;
          for(int i=n+1; i<=2*n; i++) {
               if(isPrime(i)) cnt++; 
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