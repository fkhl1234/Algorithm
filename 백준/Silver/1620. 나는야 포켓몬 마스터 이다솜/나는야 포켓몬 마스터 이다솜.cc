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

     map<string, string> dex_num;
     map<string, string> dex_str;
     for(int i=0; i<n; i++) {
          string str;
          getline(cin, str);

          dex_num.insert(make_pair(to_string(i+1), str));
          dex_str.insert(make_pair(str, to_string(i+1)));
     }

     vector<string> result;
     for(int i=0; i<m; i++) {
          string str;
          getline(cin, str);
          
          if(isdigit(str[0])) {
               result.push_back(dex_num[str]);
          }
          else result.push_back(dex_str[str]);
     }

     for(auto x: result) {
          printf("%s\n", x.c_str());
     }

     return 0;
}