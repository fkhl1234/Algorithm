#include <iostream>
#include <cstdio>

using namespace std;

bool not_selfnum[10001] = {0, };

void self_number(int n);

int main() {

     for(int i=1; i<=10000; i++) {
          if(not_selfnum[i]==false) {
               printf("%d\n", i);
               self_number(i);
          }
     }

     return 0;
     
}

void self_number(int n) {
     if(n<10000) {
          int sum = n;
          while(n>0) {
               sum += n%10;
               n /= 10;
          }

          not_selfnum[sum] = true;
          // printf("%d\n", sum);

          self_number(sum);
     }
}