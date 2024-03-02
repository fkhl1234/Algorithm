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
	int t;
	scanf("%d", &t);
	
	for(int i=0; i<t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		printf("%d\n", a+b);
	}
}