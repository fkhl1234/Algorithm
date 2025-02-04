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
#include <cmath>

using namespace std;


int n;
int num[12] = {0, };
int oper[4] = {0, };

int max_num = -INT32_MAX;
int min_num = INT32_MAX;

int calc(int num1, int num2, int i) {
     if(i==0) {
          return num1+num2;
     }
     else if(i==1) {
          return num1-num2;
     }
     else if(i==2) {
          return num1*num2;
     }
     else return num1/num2;
}

void solve(int cal, int cnt) {
     if(cnt==n) {
          if(cal>max_num) max_num = cal;
          if(cal<min_num) min_num = cal;
          
          // cout << "check" << endl;

          return;
     }

     for(int i=0; i<4; i++) {
          if(oper[i]>0) {
               oper[i]--;
               int temp = calc(cal, num[cnt], i);
               solve(temp, cnt+1);
               oper[i]++;
          }
     }

     return;
}

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n;

     for(int i=0; i<n; i++) {
          cin >> num[i];
     }

     for(int i=0; i<4; i++) {
          cin >> oper[i];
     }

     solve(num[0], 1);

     cout << max_num << endl << min_num << endl;

     return 0;
}
