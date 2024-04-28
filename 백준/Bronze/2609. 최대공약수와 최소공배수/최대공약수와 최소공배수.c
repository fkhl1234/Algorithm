#include <stdio.h>

int GCD(int a, int b);

int main()
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    int gcd = GCD(a, b);
    
    printf("%d\n", gcd);
    printf("%d\n", gcd * (a/gcd) * (b/gcd));
    
    return 0;
}

int GCD(int a, int b) {
    int r = a % b;
    
    if(r>0) {
        GCD(b, r);
    }
    else {
        return b;
    }
}
