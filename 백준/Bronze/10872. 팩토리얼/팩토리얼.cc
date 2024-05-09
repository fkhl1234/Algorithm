#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    
    printf("%d", fact);
    
    return 0;
}