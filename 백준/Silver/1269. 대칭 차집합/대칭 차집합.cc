#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
     int n, m;
     scanf("%d %d", &n, &m);

     set<int> A;
     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);

          A.insert(temp);
     }

     for(int i=0; i<m; i++) {
          int temp;
          scanf("%d", &temp);

          if(A.find(temp)!=A.end()) A.erase(temp);
          else A.insert(temp);
     }

     printf("%d\n", A.size());

     return 0;
}