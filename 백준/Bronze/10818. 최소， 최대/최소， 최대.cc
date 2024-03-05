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
	
	int min = 1000000;
	int max = -1000000;
	for(int i=0; i<N; i++) {
		int temp;
		scanf("%d", &temp);
		
		if(temp>max) max = temp;
		
		if(temp<min) min = temp;
	}
	
	printf("%d %d\n", min, max);
}