#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int x, int y, int w, int h);


int main() {
     int x, y, w, h;

     scanf("%d %d %d %d", &x, &y, &w, &h);
     
     solve(x, y, w, h);

     return 0;
}

void solve(int x, int y, int w, int h) {
     vector<int> comp = {0, 0, w, h};

     for(int i=0; i<2; i++) {
          comp[2*i] = comp[2*i]-x>0? comp[2*i]-x: x-comp[2*i];
          comp[2*i+1] = comp[2*i+1]-y>0? comp[2*i+1]-y: y-comp[2*i+1]; 
     }

     sort(comp.begin(), comp.end());

     printf("%d\n", *(comp.begin()));
}
