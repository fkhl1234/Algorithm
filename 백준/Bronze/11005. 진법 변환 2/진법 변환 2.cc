#include <iostream>
#include <cstdio>

int array[33] = {0, };

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    
    int index = 0;
    while(n>0) {
        int r = n % b;
        n /= b;
        
        array[index++] = r;
    }
    
    for(int i=index-1; i>=0; i--) {
        (array[i] < 10) ? printf("%d", array[i]) : printf("%c", 'A'+array[i]-10);
    }
    
    return 0;
}
