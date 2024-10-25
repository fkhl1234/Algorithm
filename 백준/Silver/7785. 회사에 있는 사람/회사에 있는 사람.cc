#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// // void solve(int n);
// void solve(string str, vector<string>& s);


int main() {
     int n;
     scanf("%d", &n);
     cin.ignore();

     set<string> check;
     for(int i=0; i<n; i++) {
          string str;
          getline(cin, str);

          istringstream istr(str);
          istr >> str;

          if(check.find(str)!=check.end()) check.erase(str);
          else check.insert(str); 
     }

     for(set<string>::reverse_iterator iter=check.rbegin(); iter!=check.rend(); iter++) {
          printf("%s\n", (*iter).c_str());
     }

     return 0;
}

// void solve(string str, vector<string>& s) {
//      sort(s.begin(), s.end());
//      if(s.size()>0) {
//           int temp = lower_bound(s.begin(), s.end(), str, compare) - s.begin();

//           for(int i=temp; i<11; i++) {
//                if(str.compare(s[i])==0) cnt++;
//           }

//           printf("%s : %d\n", str.c_str(), temp);
//      }
     
//      return;
// }