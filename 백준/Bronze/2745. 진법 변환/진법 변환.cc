#include <iostream>
#include <cstdio>
#include <cmath>

char array[33];
int num[32];

int main()
{
    int b;
    scanf("%s %d", array, &b);
    
    int index = 0;
    for(; array[index] != '\0'; index++);
    index--;
    
    for(int i=0; i<=index; i++) {
        if(array[i] >= 'A') {
            num[i] = array[i] - 'A' + 10;
        }
        else {
            num[i] = array[i] - '0';
        }
    }
    
    int sum = 0;
    
    for(int i=0; index>=0; i++) {
        sum += pow(b, index--) * num[i];
    }
    
    printf("%d\n", sum);
    
    return 0;
}
