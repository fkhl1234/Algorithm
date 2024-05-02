#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals
int num[33] = {0, };

int main(int argc, char* argv[]) {
	int n;
	scanf("%d", &n);
	
	if(n<0) {
		int index = 0;
		n *= -1;
		
		while(n>0) {
			num[index++] = n%2;
			n /= 2;
		}
		
		// for(int i=index-1; i>=0; i--) {
		// 	printf("%d ", num[i]);
		// }
		// printf("\n");
		
		for(int i=0; i<=index; i++) {
			if(i%2==0 && num[i]==1) {
				num[i+1]++;
			} // 홀수번째 수
			
			if(num[i]>1) {
				num[i] = 0;
				num[i+1]++;
			} // 올림처리
		}
		
		for(; num[index]==1; index++);
		for(int i=index-1; i>=0; i--) {
			printf("%d", num[i]);
		}
	}
	else if(n>0){
		int index = 0;
		
		while(n>0) {
			num[index++] = n%2;
			n /= 2;
		}
		
		// for(int i=index-1; i>=0; i--) {
		// 	printf("%d ", num[i]);
		// }
		// printf("\n");
		
		for(int i=0; i<=index; i++) {
			if(i%2==1 && num[i]==1) {
				num[i+1]++;
			} // 짝수번째 수
			
			if(num[i]>1) {
				num[i] = 0;
				num[i+1]++;
			} // 올림처리
		}
		
		for(; num[index]==1; index++);
		for(int i=index-1; i>=0; i--) {
			printf("%d", num[i]);
		}
	}
	else printf("0");
}