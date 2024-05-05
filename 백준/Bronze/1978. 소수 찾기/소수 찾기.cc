#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isprime(int num);

int main()
{
    int n;
    scanf("%d", &n);
    
    int num[100] = {0, };
    for(int i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    
    bool check[100] = {0, };
    
    int cnt = 0;
    for(int i=0; i<n; i++) {
        check[i] = isprime(num[i]);
        
        if(check[i]) cnt++;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

bool isprime(int num) {
    if(num==1) {
        return false;
    }
    else if(num==2) {
        return true;
    }
    else {
        for(int i=2; i*i<=num; i++) {
            if(num%i==0) return false; 
        }
        return true;
    }
}