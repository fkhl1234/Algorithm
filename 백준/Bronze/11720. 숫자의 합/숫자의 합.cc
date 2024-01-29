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
	int num;
	scanf("%d", &num);
	
	int sum = 0;
	
	for(int i=0; i<num; i++) {
		int d;
		scanf("%1d", &d);
		
		sum += d;
	}
	
	printf("%d\n", sum);
}