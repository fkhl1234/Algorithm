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
	int x, y;
	scanf("%d %d", &x, &y);
	
	if(x>0) {
		if(y>0) printf("1\n");
		else printf("4\n");
	}
	else {
		if(y>0) printf("2\n");
		else printf("3\n");
	}
}