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
	char string[1001];
	scanf("%s", string);
	
	int d;
	scanf("%d", &d);
	
	printf("%c\n", string[d-1]);
}