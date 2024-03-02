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
	int array[10000];
	
	int i=0;
	while(1) {
		int n, m;
		scanf("%d %d", &n, &m);
		
		if(n==0) {
			break;
		}
		
		array[i] = n+m;
		i++;
	}
	
	for(int j=0; j<i; j++) {
		printf("%d\n", array[j]);
	}
}