#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long int GCD(long long int a, long long int b);

int main() {
     int n;
     scanf("%d", &n);

     vector<int> tree;
     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);

          tree.push_back(temp);
     }

     vector<int> interval;
     for(int i=0; i<n-1; i++) {
          int intv = tree[i+1] - tree[i];

          interval.push_back(intv);
     }

     int gcd;
     for(int i=0; i<n-2; i++) {
          gcd = interval[i]>interval[i+1] ? GCD(interval[i], interval[i+1]) : GCD(interval[i+1], interval[i]);
          interval[i+1] = gcd;
     }

     int dis = tree[n-1] - tree[0];
     dis /= gcd;
     dis = dis - n + 1;

     printf("%d\n", dis);

     return 0;
}

//GCD(a, b) = GCD(b, r) (r = a % b)

long long int GCD(long long int a, long long int b) {
     long long int r = a % b;
     if(r==0) return b;
     return GCD(b, r);
}