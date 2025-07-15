#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
    scanf("%d", &n);

    vector<int> dist;
    for(int i=0; i<n-1; i++) {
        int tmp;
        scanf("%d", &tmp);

        dist.push_back(tmp);
    }

    vector<int> price;
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);

        price.push_back(tmp);
    }

    int min_idx = 0;
    vector<int> min_city;
    min_city.push_back(0);
    for(int i=0; i<n-1; i++) {
        if(price[i] < price[min_idx]) {
            min_idx = i;
            min_city.push_back(i);
        }
    }
    min_city.push_back(n-1);

    long long int sum = 0;
    int start_idx = 0;
    for(int i=0; i<min_city.size()-1; i++) {
        long long int dist_sum = 0;
        for(int j=min_city[i]; j<min_city[i+1]; j++) {
            dist_sum += dist[j];
        }

        sum += dist_sum * price[min_city[i]];
    }

    printf("%lld\n", sum);

    return 0;
}
