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

void kantore(vector<int>& arr, int start, int end);

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     int n;
     while(scanf("%d", &n)!=EOF) {
          int num = pow(3, n);

          vector<int> array(num+1, 1);

          kantore(array, 1, num);

          for(int i=1; i<=num; i++) {
               if(array[i]) printf("-");
               else printf(" ");
          }
          printf("\n");
     }
}

void kantore(vector<int>& arr, int start, int end) {
     int one_third = (end-start+1)/3;

     if(one_third>=1) {
          int mid1 = start+one_third-1;
          int mid2 = start+one_third*2-1;

          for(int i=1; i<=one_third; i++) arr[i+mid1] = 0;

          kantore(arr, start, mid1);
          kantore(arr, mid1+1, mid2);
          kantore(arr, mid2+1, end);
     }
}