#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int arr[1001] = {0, };
int dp[1001] = {0, };

int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	// dp[i] : arr[i]가 마지막 수가 되는 LIS
	for(int i=0; i<n; i++) {
		dp[i] = 1;
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	auto it = *max_element(dp, dp+n);
	printf("%d", it);
	return 0;
}
