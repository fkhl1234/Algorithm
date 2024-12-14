#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {   
     int n;
     scanf("%d", &n);

     deque<pair<int, int>> circle;
     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);

          circle.push_back(make_pair(i+1, temp));
     }

     vector<int> order;
     while(!circle.empty()) {
          pair<int, int> front_pair = circle.front();
          int cmd = front_pair.second;
          int index = front_pair.first;

          order.push_back(index);
          circle.pop_front();

          if(circle.empty()) break;

          if(cmd>0) {
               for(int i=0; i<cmd-1; i++) {
                    pair<int, int> temp = circle.front();
                    circle.pop_front();
                    circle.push_back(temp);
               }
          }
          else {
               cmd *= -1;
               for(int i=0; i<cmd; i++) {
                    pair<int, int> temp = circle.back();
                    circle.pop_back();
                    circle.push_front(temp);
               }
          }
     }

     for(auto x: order) {
          printf("%d ", x);
     }
}