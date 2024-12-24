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

using namespace std;

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // input
     int n;
     cin >> n;
     
     double sum = 0;
     vector<int> array;
     for(int i=0; i<n; i++) {
          double temp;
          cin >> temp;

          sum += temp;
          array.push_back(temp);
     }

     sort(array.begin(), array.end());
     
     printf("%d\n", (int)(sum/n + (sum/n > 0 ? 0.5 : -0.5)));
     printf("%d\n", array[n/2]); 

     map<int, int> fre;
     for(auto x: array) {
          fre[x]++;
     }

     int max = 0;
     vector<int> maxint;
     for(auto x: fre) {
          if(max<x.second) {
               maxint.clear();
               maxint.push_back(x.first);
               max = x.second;
          }
          else if(max==x.second) maxint.push_back(x.first);
     }

     sort(maxint.begin(), maxint.end());

     if(maxint.size()>1) printf("%d\n", maxint[1]);
     else printf("%d\n", maxint[0]);


     // printf("%d\n", );
     printf("%d\n", array[n-1]-array[0]);
}