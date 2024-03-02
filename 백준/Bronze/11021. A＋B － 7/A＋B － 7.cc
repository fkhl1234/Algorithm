#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals

int main(int argc, char* argv[]) {
	int N;
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		
		printf("Case #%d: %d\n", i+1, n+m);
	}
}