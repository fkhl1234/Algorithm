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
	int T;
	scanf("%d", &T);
	
	for(int i=1; i<=T; i++) {
		for(int j=1; j<=T-i; j++) {
			printf(" ");
		}
		for(int j=1; j<=2*i-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	for(int i=1; i<=T-1; i++) {
		for(int j=1; j<=i; j++) {
			printf(" ");
		}
		for(int j=1; j<=(T-1-i)*2+1; j++) {
			printf("*");
		}
		printf("\n");
	}
}