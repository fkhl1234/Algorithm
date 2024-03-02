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
	int price;
	int N;
	scanf("%d %d", &price, &N);
	
	int sum = 0;
	for(int i=0; i<N; i++) {
		int cost, amount;
		scanf("%d %d", &cost, &amount);
		
		sum += cost*amount;
	}
	
	if(price==sum) printf("Yes\n");
	else printf("No");
}