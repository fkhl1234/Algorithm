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
	int A, B;
	scanf("%d %d", &A, &B);
	
	printf("%d\n", A*(B%10));
	printf("%d\n", A*((B/10)%10));
	printf("%d\n", A*((B/100)%10));
	
	printf("%d\n", A*B);
}