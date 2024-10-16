#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n);
// void solve(vector<int>& integer, int n);

int number[10001] = {0, };

int main() {
     int n;
     scanf("%d", &n);
     
     solve(n);

     return 0;
}

void solve(int n) {
     vector<int> digit;

     while(n>0) {
          int temp = n%10;
          n /= 10;
          digit.push_back(temp);
     }

     sort(digit.begin(), digit.end());

     for(vector<int>::reverse_iterator iter=digit.rbegin(); iter!=digit.rend(); iter++) {
          printf("%d", *iter);
     }

     return;
}