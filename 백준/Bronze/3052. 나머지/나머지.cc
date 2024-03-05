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
	bool array[42] = {0, };
	
	for(int i=0; i<10; i++) {
		int temp;
		scanf("%d", &temp);
		
		array[temp%42] = true;
	}
	
	int cnt = 0;
	for(int i=0; i<=41; i++) {
		if(array[i]) cnt++;
	}
	
	printf("%d\n", cnt);
}