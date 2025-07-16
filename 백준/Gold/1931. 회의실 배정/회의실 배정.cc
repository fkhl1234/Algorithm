#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

int dp[200001] = {0, };

int main() {
	int n;
    scanf("%d", &n);

    vector<pair<int, int>> schedule;

    for(int i=0; i<n; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        schedule.push_back({end, start});
    }

    sort(schedule.begin(), schedule.end());
    
    int end_time = schedule[0].first;
    int count = 1;
    for(int i=1; i<n; i++) {
        if(end_time<=schedule[i].second) {
            count++;
            end_time = schedule[i].first;
        }
    }

    printf("%d\n", count);

    return 0;
}
