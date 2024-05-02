#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals
int num[1000000] = {0, };
int octa[400000] = {0, };

int main(int argc, char* argv[]) {
	int a;
	int index = 0;
	while((a=getchar())!='\n') {
		octa[index++] = a-'0';
	}
	
	// for(int i = index-1; i>=0; i--) {
	// 	printf("%d ", octa[i]);
	// }
	// printf("\n");
	
	for(int i=0; i<index; i++) {
		int temp = octa[i];
		
		num[3*i + 2] = temp%2;
		temp /= 2;
		
		num[3*i + 1] = temp%2;
		temp /= 2;
		
		num[3*i] = temp%2;
	}
	
	int o = 3*(index-1)+2;
	int s = 0;
	for(; num[s]==0; s++);
	
	if(s>o) {
		printf("0");
		return 0;
	}
	
	for(int i=s; i<=o; i++) {
		printf("%d", num[i]);
	}
	return 0;
}