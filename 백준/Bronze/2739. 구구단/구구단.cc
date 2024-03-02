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
	
	for(int i=1; i<=9; i++) {
		printf("%d * %d = %d\n", num , i, num*i);
	}
}