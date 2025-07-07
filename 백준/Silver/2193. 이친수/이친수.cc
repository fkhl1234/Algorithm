#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	scanf("%d", &N);

	// 0과 1로 끝나는 이친수의 개수
	long long int end0 = 1;
	long long int end1 = 0;

	// N=3일 때부터 성립
	for(int i=3; i<=N; i++) {
		long long int temp = end0;
		end0 += end1;
		end1 = temp;
	}

	printf("%lld\n", end0+end1);
}
