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

using namespace std;

void merge_sort(vector<int>& arr, int start, int end);
void merge(vector<int>& arr, int start, int mid, int end);

int m;
int cnt = 0;

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     int n;
     cin >> n >> m;

     vector<int> array;
     for(int i=0; i<n; i++) {
          int tmp;
          cin >> tmp;

          array.push_back(tmp);
     }

     merge_sort(array, 0, n-1);

     // for(auto x: array) cout << x << " ";

     if(cnt < m) printf("-1");

     return 0;
}

void merge_sort(vector<int>& arr, int start, int end) {
     if(start<end) {
          int mid = (start+end)/2;
          
          merge_sort(arr, start, mid);
          merge_sort(arr, mid+1, end);
          merge(arr, start, mid, end);
     }
}


void merge(vector<int>& arr, int start, int mid, int end) {
     vector<int> tmp;

     int i = start;
     int j = mid+1;

     while(i<=mid && j<=end) {
          if(arr[i]<arr[j]) {
               tmp.push_back(arr[i++]);

          } 
          else tmp.push_back(arr[j++]);
     }

     while(i<=mid) tmp.push_back(arr[i++]);
     while(j<=end) tmp.push_back(arr[j++]);

     i = start;
     int t = 0;
     while(i<=end) {
          arr[i++] = tmp[t++];
          cnt++;

          if(cnt==m) {
               printf("%d\n", arr[i-1]);
          }
     }
}