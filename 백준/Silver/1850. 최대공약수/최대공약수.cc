#include <iostream>
#include <cstdio>

long int gcd(long int a, long int b);

int main()
{
    long int a, b;
    scanf("%ld %ld", &a, &b);
    
    long int big = (a>b) ? a : b;
    long int small = (a>b) ? b : a;
    
    long int g = gcd(big, small);
    
    for(int i=0; i<g; i++) {
        printf("1");
    }
    
    return 0;
}

long int gcd(long int a, long int b) {
    long int r = a % b;
    
    if(r>0) {
        long int z = gcd(b, r);
        return z;
    }
    else {
        return b;
    }
}
