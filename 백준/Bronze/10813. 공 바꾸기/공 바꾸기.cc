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
	int N, M;
	scanf("%d %d", &N, &M);
	
	int basket[101] = {0, };
	
	for(int i=1; i<=N; i++) {
		basket[i] = i;
	}
	
	for(int i=0; i<M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		
		int temp;
		temp = basket[from];
		basket[from] = basket[to];
		basket[to] = temp;
	}
	
	for(int i=1; i<=N; i++) printf("%d ", basket[i]);
}