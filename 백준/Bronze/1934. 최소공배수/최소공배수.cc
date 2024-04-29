#include <iostream>
#include <cstdio>

int gcd(int a, int b);

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int i=0; i<T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int g = gcd(a, b);
        
        printf("%d\n", g * (a/g) * (b/g));
    }
    
    return 0;
}

int gcd(int a, int b) {
    int r = a % b;
    
    if(r>0) {
        int z = gcd(b, r);
        return z;
    }
    else {
        return b;
    }
}
