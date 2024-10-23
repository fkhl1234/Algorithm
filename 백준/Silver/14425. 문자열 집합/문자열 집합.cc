#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// // void solve(int n);
// void solve(string str, vector<string>& s);

// int binary_search(vector<int>& pool, int target, int start, int end);
bool compare(string str1, string str2);
// 

int main() {
     int n, m;
     scanf("%d %d", &n, &m);
     cin.ignore();

     vector<string> s;
     for(int i=0; i<n; i++) {
          string str;
          getline(cin, str);
          s.push_back(str);
     }

     sort(s.begin(), s.end());
     
     int cnt = 0;
     
     for(int i=0; i<m; i++) {
          string str;
          getline(cin, str);
          
          if(binary_search(s.begin(), s.end(), str)) cnt++;
     }

     printf("%d\n", cnt);

     return 0;
}