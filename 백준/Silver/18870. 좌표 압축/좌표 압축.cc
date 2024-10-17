#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void solve(int n);
void solve(vector<int>& dict);

int main() {
     int n;
     scanf("%d", &n);

     vector<int> dict;
     for(int i=0; i<n; i++) {
          int age;
          scanf("%d", &age);
          dict.push_back(age);
     }
     
     solve(dict);

     return 0;
}

void solve(vector<int>& dict) {
     vector<int> temp(dict);

     sort(temp.begin(), temp.end());
     temp.erase(unique(temp.begin(), temp.end()), temp.end());
     
     // for(int i=0; i<dict.end()-dict.begin(); i++) {
     //      int index = lower_bound(temp.begin(), temp.end(), dict[i]) - dict.end();

     //      printf("%d ", index);
     // }

     for(auto x: dict) {
          int index = lower_bound(temp.begin(), temp.end(), x) - temp.begin();

          printf("%d ", index);
     }
     
     return;
}