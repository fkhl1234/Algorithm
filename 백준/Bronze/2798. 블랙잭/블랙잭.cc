#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
     int N, M;
     scanf("%d %d", &N, &M);

     vector<int> card(N);
     for(int i=0; i<N; i++) {
          scanf("%d", &card[i]);
     }

     int max = 0;
     int sum;

     for(int i=0; i<N-2; i++) {
          for(int j=i+1; j<N-1; j++) {
               for(int k=j+1; k<N; k++) {
                    sum = card[i] + card[j] + card[k];

                    if(sum<M) {
                         if(sum>max) {
                              max = sum;
                         }
                    }
                    else if(sum==M) {
                         max = sum;
                         break;
                    }
               }
          }
     }

     printf("%d", max);
}