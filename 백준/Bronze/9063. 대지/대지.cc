#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<pair<int, int>> & ex);


int main() {
     int n;
     scanf("%d", &n);

     vector<pair<int, int>> coord;
     for(int i=0; i<n;i++) {
          int x, y;
          scanf("%d %d", &x, &y);

          coord.push_back(make_pair(x, y));
     }

     if(n==1) {
          printf("0\n");
          return 0;
     }

     solve(coord);

     return 0;
}

void solve(vector<pair<int, int>> & ex){
     pair<int, int> max = make_pair(-10000, -10000);
     pair<int, int> min = make_pair(10000, 10000);

     for(pair<int ,int> temp: ex) {
          max.first = max.first<temp.first ? temp.first : max.first;
          max.second = max.second<temp.second ? temp.second : max.second;
          
          min.first = min.first>temp.first ? temp.first : min.first;
          min.second = min.second>temp.second ? temp.second : min.second;
     }    

     // printf("%d %d\n", max.first, max.second);
     // printf("%d %d\n", min.first, min.second);

     // printf("%d\n", max.first-min.first);
     // printf("%d\n", max.second-min.second);

     printf("%d\n", (max.first-min.first)*(max.second-min.second));
}
