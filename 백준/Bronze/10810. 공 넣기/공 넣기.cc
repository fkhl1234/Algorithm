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
	
	for(int i=0; i<M; i++) {
		int from, to, num;
		scanf("%d %d %d", &from, &to, &num);
		
		for(int i=from; i<=to; i++) {
			basket[i] = num;
		}
	}
	
	for(int i=1; i<=N; i++) printf("%d ", basket[i]);
}