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
	int ans[6] = {1, 1, 2, 2, 2, 8};
	
	for(int i=0; i<6; i++) {
		int temp;
		scanf("%d", &temp);
		ans[i] -= temp;
	}
	
	for(int i=0; i<6; i++) {
		printf("%d ", ans[i]);
	}
}