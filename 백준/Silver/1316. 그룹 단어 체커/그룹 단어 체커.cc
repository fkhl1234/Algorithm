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
	
	int cnt = 0;
	
	for(int i=0; i<T; i++) {
		char str[101];
		scanf("%s", str);
		
		bool arr[26] = {0, };
		
		for(int i=0; str[i]!='\0'; i++) {
			char c = str[i];
			if(!arr[c-'a']) {
				arr[c-'a'] = true;
				
				for(;str[i]==str[i+1]; i++) {}
			}
			else {
				cnt--;
				break;
			}
		}
		cnt++;
	}
	
	printf("%d\n", cnt);
}