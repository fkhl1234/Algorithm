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
	
	for(int i=0; i<T; i++) {
		int R;
		char s;
		
		scanf("%d ", &R);
		while((s=getchar())!='\n') {
			for(int i=0; i<R; i++) {
				printf("%c", s);
			}
		}
		
		printf("\n");
	}
}