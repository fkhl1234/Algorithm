#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool _compare(pair<int, int> &control, pair<int, int> &comparison);

int main() {
     int N;
     scanf("%d", &N);

     vector<pair<int, int>> body(N);
     for(int i=0; i<N; i++) {
          int x, y;
          scanf("%d %d", &x, &y);

          body[i] = make_pair(x, y);
     }

     vector<int> ranking(N);

     for(int i=0; i<N; i++) {
          for(int j=0; j<N; j++) {
               bool check = _compare(body[i], body[j]);

               if(check) ranking[i]++;
          }
     }

     for(int i=0; i<N; i++) {
          printf("%d ", ranking[i]+1);
     }
}

bool _compare(pair<int, int> &control, pair<int, int> &comparison) {
     if(control.first < comparison.first && control.second < comparison.second) {
          return true;
     }
     else return false;
}