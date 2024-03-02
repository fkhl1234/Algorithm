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
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N-i; j++) printf(" ");
		for(int j=1; j<=i; j++) printf("*");
		
		printf("\n");
	}
}