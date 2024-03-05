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
	bool check[31] = {0, };
	
	for(int i=0; i<28; i++) {
		int temp;
		scanf("%d", &temp);
		
		check[temp] = true;
	}
	
	for(int i=1; i<=30; i++) {
		if(!check[i]) printf("%d\n", i);
	}
}