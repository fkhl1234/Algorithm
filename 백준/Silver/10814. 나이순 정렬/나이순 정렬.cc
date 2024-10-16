#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void solve(int n);
void solve(vector<pair<int, string>> dict);

bool compare(pair<int, string> temp1, pair<int, string> temp2);

int main() {
     int n;
     scanf("%d", &n);
     cin.ignore();

     vector<pair<int, string>> dict;
     for(int i=0; i<n; i++) {
          int age;
          scanf("%d", &age);
          cin.ignore();

          string str;
          getline(cin , str);

          dict.push_back(make_pair(age, str));
     }
     
     solve(dict);

     return 0;
}

void solve(vector<pair<int, string>> dict) {
     stable_sort(dict.begin(), dict.end(), compare);
     
     for(auto x: dict) {
          printf("%d %s \n", x.first, x.second.c_str());
     }
     return;
}

bool compare(pair<int, string> temp1, pair<int, string> temp2) {
     return temp1.first<temp2.first;
}