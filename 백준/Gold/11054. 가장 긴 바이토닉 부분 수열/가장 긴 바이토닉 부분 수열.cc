#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int arr[1001] = {0, };
int dpF[1001] = {0, };
int dpB[1001] = {0, };

int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	// dpF[i] : arr[i]가 마지막 수가 되는 정방향 LIS
	for(int i=0; i<n; i++) {
		dpF[i] = 1;
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i]) {
				dpF[i] = max(dpF[i], dpF[j]+1);
			}
		}
	}
	
	// dpB[i] : arr[i]가 마지막 수가 되는 역방향 LIS
	for(int i=n-1; i>=0; i--) {
		dpB[i] = 1;
		for(int j=n-1; j>i; j--) {
			if(arr[j] < arr[i]) {
				dpB[i] = max(dpB[i], dpB[j]+1);
			}
		}
	}

	// dp[i] : arr[i]에서의 역방향 LIS + 정방향 LIS
	int dp[1001];
	for(int i=0; i<n; i++) {
		dp[i] = dpF[i] + dpB[i];
	}

	// dp[i]는 arr[i]가 중복되어 있어서 -1
	auto it = *max_element(dp, dp+n);
	printf("%d", it-1);
	
	return 0;
}
