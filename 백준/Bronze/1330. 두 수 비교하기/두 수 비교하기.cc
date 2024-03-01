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
	
	if(A>B) printf(">\n");
	else if(A==B) printf("==\n");
	else printf("<\n");
}