#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue> 

using namespace std;

bool dict_sort(pair<string, int>a, pair<string, int> b) {
     if(a.second!=b.second) return a.second > b.second;
     else {
          if(a.first.length()!=b.first.length()) return a.first.length() > b.first.length();
          else {
               return a.first < b.first;
          }
     }
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // input
     int n, m;
     cin >> n >> m;

     unordered_map<string, int> dict;

     for(int i=0; i<n; i++) {
          string str;
          cin >> str;

          if(str.length()>=m) dict[str]++;
     }

     // solve
     vector<pair<string, int>> dict_solve;
     for(auto x: dict) {
          dict_solve.push_back(make_pair(x.first, x.second));
     }

     sort(dict_solve.begin(), dict_solve.end(), dict_sort);

     for(auto x: dict_solve) {
          cout << x.first << "\n";
     }

}