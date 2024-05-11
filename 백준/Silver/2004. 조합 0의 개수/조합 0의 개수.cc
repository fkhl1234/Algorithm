#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    if(m>n-m) m = n-m; 
    
    int five = 0, two = 0;
    
    for(long i=2; i<=n; i*=2) {
        two += n/i;
    }
    for(long i=2; i<=n-m; i*=2) {
        two -= (n-m)/i;
    }
    for(long i=2; i<=m; i*=2) {
        two -= m/i;
    }
    
    for(long i=5; i<=n; i*=5) {
        five += n/i;
    }
    for(long i=5; i<=n-m; i*=5) {
        five -= (n-m)/i;
    }
    for(long i=5; i<=m; i*=5) {
        five -= m/i;
    }
    
    printf("%d", (five>two)?two:five);
    
    return 0;
}