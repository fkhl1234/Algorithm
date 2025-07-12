#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char a[1001], b[1001];
int dp[1001][1001] = {0, };

int main() {
    scanf("%s", a + 1);
    scanf("%s", b + 1);

	// 각 문자열 길이
    int lenA = strlen(a + 1);
    int lenB = strlen(b + 1);

	// dp로 LCS 찾기
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[lenA][lenB]);
    return 0;
}
