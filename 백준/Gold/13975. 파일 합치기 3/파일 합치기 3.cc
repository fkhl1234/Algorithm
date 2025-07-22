#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for(int a=0; a<T; a++) {
        int n;
        scanf("%d", &n);
        
        priority_queue<long long int, vector<long long int>, greater<long long int>> chapter;

        for(int i=0; i<n; i++) {
            int tmp;
            scanf("%d", &tmp);

            chapter.push(tmp);
        }

        vector<long long int> cost;
        while(chapter.size()>1) {
            long long int min1 = chapter.top();
            chapter.pop();
            long long int min2 = chapter.top();
            chapter.pop();

            cost.push_back(min1+min2);
            chapter.push(min1+min2);
        }
        
        long long sum = 0;
        for(auto x: cost) {
            sum += x;
        }
        printf("%lld\n", sum);
    }
    
    return 0;
}
