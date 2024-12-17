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

using namespace std;

int main() {
     int n, k;
     scanf("%d %d", &n, &k);

     int cnt = 1;
     int div = 1;
     for(int i=0; i<k; i++) {
          cnt *= (n-i);
          div *= (i+1);
     }

     printf("%d", cnt/div);
}