#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {  
     // input
     int n;
     vector<int> qORs;
     vector<int> queuestack;
     int m;
     vector<int> input;
     
     scanf("%d", &n);

     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);

          qORs.push_back(temp);
     }

     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d",&temp);
          
          if(qORs[i]==0) queuestack.push_back(temp);
     }

     scanf("%d", &m);

     for(int i=0; i<m; i++) {
          int temp;
          scanf("%d", &temp);

          input.push_back(temp);
     }

     // solution
     int cnt = 0;
     for(vector<int>::reverse_iterator riter=queuestack.rbegin(); riter!=queuestack.rend(); riter++) {
          if(cnt==m) break;
     
          printf("%d ", *riter);
          cnt++;
     }
     for(vector<int>::iterator iter=input.begin(); iter!=input.end(); iter++) {
          if(cnt==m) break;

          printf("%d ", *iter);
          cnt++;
     }
}