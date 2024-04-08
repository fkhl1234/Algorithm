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
	scanf("%d", &T); // 테스트 케이스
	
	for(int i=0; i<T; i++) {
		int w, h, n;
		scanf("%d %d %d", &h, &w, &n);
		
		int a = n/h;
		int b = n%h; // a는 호수, b는 층수
		
		if(b==0) {
			printf("%d%02d\n", h, a);
		}
		else {
			printf("%d%02d\n", b, a+1);
		}
	}
}