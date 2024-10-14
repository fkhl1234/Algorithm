#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> & ex);


int main() {
     // while(1) {
     int a, b, c;
     scanf("%d %d %d", &a, &b, &c);

     vector<int> excreta = {a, b, c};

     solve(excreta);
     // }

     return 0;
}

void solve(vector<int> & ex){
     for(int i=0; i<3; i++) {
          for(int j=i+1; j<3; j++) {
               if(ex[j]<ex[i]) {
                    int temp = ex[j];
                    ex[j] = ex[i];
                    ex[i] = temp;
               }
          }
     }

     if(ex[2]+ex[0]+ex[1]!=180) {
          printf("Error\n");
          return;
     }

     int temp = ex[1];
     for(vector<int>::iterator iter=ex.begin(); iter!=ex.end(); iter++) {
          *iter -= temp;
     }

     int cnt = 0;
     for(auto x: ex) {
          if(x==0) cnt++;
     }

     if(cnt==3) printf("Equilateral\n");
     else if(cnt==2) printf("Isosceles\n");
     else printf("Scalene\n");
}
