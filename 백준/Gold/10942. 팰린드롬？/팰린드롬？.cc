#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//Funtions

int main(int argc, char* argv[]) {
	int N;
	scanf("%d", &N);
	
	int* num = (int*)malloc(sizeof(int)*(N+1));
	for(int i=1; i<=N; i++) {
		scanf("%d", &num[i]);
	}
	
	int M;
	scanf("%d", &M);
	int** quest = (int**)malloc(sizeof(int*)*(M+1));
	for(int i=1; i<=M; i++) {
		quest[i] = (int*)malloc(sizeof(int)*2);
	}
	for(int i=1; i<=M; i++) {
		scanf("%d %d", &quest[i][0], &quest[i][1]);
	}
	
	int* D = (int*)malloc(sizeof(int)*(N+1)); // 홀수용
	for(int i=0; i<=N; i++) {
		D[i] = 0;
	}

	int* E = (int*)malloc(sizeof(int)*(N+1)); // 홀수용
	for(int i=0; i<=N; i++) {
		E[i] = -1;
	}
	
	for(int i=1; i<=M; i++) {
		if((quest[i][1]-quest[i][0]) % 2 == 0) {
			int center = (quest[i][1] + quest[i][0])/2;
			int len = quest[i][1] - center;
			
			if(len>D[center]){
				for(int i=D[center]+1; i<=len; i++) {
					if(num[center-i] == num[center+i]) {
						D[center]++;
					}
					else {
						printf("0\n");
						break;
					}
				}
				if(D[center]>=len) printf("1\n");
			}
			else printf("1\n");
		}
		else {
			int center = (quest[i][1] + quest[i][0])/2;
			int len = center - quest[i][0];
			
			if(len>E[center]){
				for(int i=E[center]+1; i<=len; i++) {
					if(num[center-i] == num[center+1+i]) {
						E[center]++;
					}
					else {
						printf("0\n");
						break;
					}
				}
				if(E[center]>=len) printf("1\n");
			}
			else printf("1\n");
		}
	}
}