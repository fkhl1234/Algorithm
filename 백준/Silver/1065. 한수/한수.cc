#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
     int N;
     scanf("%d", &N);

     bool isHan[1001] = {0, };

     for(int i=0; i<=9; i++) {
          for(int d=0; d<=9; d++) {
               int index1 = i;
               int index2 = i+d;
               int index3 = i+2*d;

               isHan[index1] = true;
               // printf("%d\n", index1);

               if(index2/10==0) {
                    isHan[10*index2 + index1] = true;
                    // printf("%d\n", index2*10 + index1);
                    
                    if(index3/10==0) {
                         isHan[100*index3 + 10*index2 + index1] = true;
                         // printf("%d\n", 100*index3 + 10*index2 + index1);
                    }
               }
          }
          for(int d=-9; d<0; d++) {
               int index1 = i;
               int index2 = i+d;
               int index3 = i+2*d;

               if(index1>=0) isHan[index1] = true;
               // printf("%d\n", index1);

               if(index2/10==0 && index2>=0) {
                    isHan[10*index2 + index1] = true;
                    // printf("%d\n", index2*10 + index1);
                    
                    if(index3/10==0 && index3>=0) {
                         isHan[100*index3 + 10*index2 + index1] = true;
                         // printf("%d\n", 100*index3 + 10*index2 + index1);
                    }
               }
          }
     }

     int cnt = 0;

     for(int i=1; i<=N; i++) {
          if(isHan[i]) cnt++;
     }

     printf("%d", cnt);
}