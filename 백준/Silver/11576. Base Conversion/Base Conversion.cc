#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    int n;
    scanf("%d", &n);
    vector<int> future(n); // a진법
    
    for(int i=0; i<n; i++) {
        scanf("%d", &future[i]);
    }
    
    int deci = 0;
    for(int i=n-1; i>=0; i--) {
        deci += future[n-1-i] * pow(a, i);
    }
    
    // printf("%d\n", deci);
    
    vector<int> present;
    while(deci>0) {
        int temp = deci%b;
        present.push_back(temp);
        deci /= b;
    }

    for(vector<int>::iterator iter = present.end()-1; iter>=present.begin(); iter--) {
        printf("%d ", *iter);
    }
    
    return 0;
}
