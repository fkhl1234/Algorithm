#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
     int n, m;
     scanf("%d %d", &n, &m);
     cin.ignore();

     vector<string> seen;
     for(int i=0; i<n; i++) {
          string str;
          getline(cin, str);

          seen.push_back(str);
     }

     sort(seen.begin(), seen.end());

     vector<string> heard;
     for(int i=0; i<m; i++) {
          string str;
          getline(cin, str);

          heard.push_back(str);
     }

     int cnt = 0;
     vector<string> result;
     for(int i=0; i<m; i++) {
          int index = lower_bound(seen.begin(), seen.end(), heard[i]) - seen.begin();

          if(heard[i].compare(seen[index])==0) {
               cnt++;
               result.push_back(heard[i]);
          }
     }

     printf("%d\n", cnt);
     sort(result.begin(), result.end());
     for(auto x: result) printf("%s\n", x.c_str());

     return 0;
}