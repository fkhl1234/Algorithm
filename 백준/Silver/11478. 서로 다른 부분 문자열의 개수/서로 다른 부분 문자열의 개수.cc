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
     string str;
     getline(cin, str);

     set<string> part;
     
     for(int i=1; i<=str.length(); i++) {
          for(int j=0; j<str.length()-i+1; j++) {
               string temp = str.substr(j, i);

               part.insert(temp);
          }
     }

     // for(string x: part) printf("%s\n", x.c_str());

     printf("%d\n", part.size());

     return 0;
}