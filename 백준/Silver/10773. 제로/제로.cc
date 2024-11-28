#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main() {
     int k;
     scanf("%d", &k);

     stack<int> st;

     for(int i=0; i<k; i++) {
          int temp;
          scanf("%d", &temp);

          if(temp==0) st.pop();
          else st.push(temp); 
     }

     int sum = 0;
     while(!st.empty()) {
          sum += st.top();
          st.pop();
     }

     printf("%d\n", sum);
}
