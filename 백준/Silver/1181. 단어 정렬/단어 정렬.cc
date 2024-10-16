#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void solve(int n);
void solve(vector<string> dict);

bool compare(string temp1, string temp2);

int main() {
     int n;
     scanf("%d", &n);
     cin.ignore();

     vector<string> dict;
     for(int i=0; i<n; i++) {
          string str;
          getline(cin , str);

          dict.push_back(str);
     }
     
     solve(dict);

     return 0;
}

void solve(vector<string> dict) {
     sort(dict.begin(), dict.end(), compare);

     for(vector<string>::iterator iter=dict.begin(); iter!=dict.end(); iter++) {
          if(*iter!=*(iter+1)) {
               printf("%s\n", (*iter).c_str());
          }
     }
     return;
}

bool compare(string temp1, string temp2) {
     if(temp1.length()!=temp2.length()) return temp1.length() < temp2.length();
     else {
          for(int i=0; i<temp1.length(); i++) {
               if(temp1[i]!=temp2[i]) {
                    // printf("%c %c\n", temp1[i], temp2[i]);
                    return temp1[i]<temp2[i];
               }  
          }
     } 
}