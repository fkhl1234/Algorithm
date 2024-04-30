#include <iostream>
#include <cstdio>

int array[101] = {0, };

int gcd(int a, int b);

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int a=0; a<T; a++) {
        int n;
        scanf("%d", &n);
        
        for(int i=0; i<n; i++) {
            scanf("%d", &array[i]);
        }
        
        long int sum = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                sum += gcd(array[i], array[j]);
            }
        }
        
        printf("%ld\n", sum);
    }
    
    return 0;
}

int gcd(int a, int b) {
    int r = a % b;
    if(r>0) {
        return gcd(b, r);
    }
    else {
        return b;
    }
}