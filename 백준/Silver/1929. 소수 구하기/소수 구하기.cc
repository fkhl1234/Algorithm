#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool notprime[1000000] = {0, };
int prime[1000000];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    notprime[1] = true;
    for(int i=2; i*i<=M; i++) {
        if(!notprime[i]) {
            for(int j=i*2; j<=M; j+=i) {
                notprime[j] = true;
            }
        }
    }
    
    for(int i=N; i<=M; i++) {
        if(!notprime[i]) printf("%d\n", i);
    }
    
    return 0;
}