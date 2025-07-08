#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define MOD 9901

using namespace std;

// 각 길이 N에서의 경우의 수 3가지 : L, R, None
long long int dp[100001][3] = {0, };

int main(int argc, char** argv)
{
	int N;
	scanf("%d", &N);
	
	// 초기값 세팅
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	// 추가된 길이마다 3가지 경우의 수를 계산
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }

    int result = (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;

	printf("%lld\n", result);

	return 0;
}
