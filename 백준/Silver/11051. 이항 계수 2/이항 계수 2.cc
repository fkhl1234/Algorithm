#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int dp[1002][1002] = {0, };

int main(int argc, char** argv)
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	// 초기값 세팅
	dp[1][0] = 1;
	dp[1][1] = 1;

	// 이항계수 점화식 활용
	for(int i=2; i<=N; i++) {
		dp[i][0] = 1;
		for(int j=1; j<=i; j++) {
			dp[i][j] = ((dp[i-1][j-1] % 10007) + (dp[i-1][j] % 10007)) % 10007;
		}
	}

	printf("%d\n", dp[N][K]);
}
