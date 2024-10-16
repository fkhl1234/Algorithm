#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// void solve(int n);
void solve(vector<pair<int, int>> coord);

bool compare(pair<int, int> temp1, pair<int, int> temp2);

int main() {
     int n;
     scanf("%d", &n);

     vector<pair<int, int>> coord;
     for(int i=0; i<n; i++) {
          int x, y;
          scanf("%d %d", &x, &y);

          coord.push_back(make_pair(x, y));
     }
     
     solve(coord);

     return 0;
}

void solve(vector<pair<int, int>> coord) {
     sort(coord.begin(), coord.end(), compare);

     for(auto x: coord) {
          printf("%d %d\n", x.first, x.second);
     }

     return;
}

bool compare(pair<int, int> temp1, pair<int, int> temp2) {
     if(temp1.first!=temp2.first) return temp1.first<temp2.first;
     else return temp1.second<temp2.second;
}