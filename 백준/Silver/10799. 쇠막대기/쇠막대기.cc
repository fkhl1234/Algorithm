#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//Globals
char strings[100001] = {0, };

int main(int argc, char* argv[]) {
	scanf("%s", strings);
	
	stack<int> s;
	int cnt = 0;
	int sum = 0;
	
	for(int i=0; strings[i]!='\0'; i++) {
		if(strings[i] == '(') {
			if(strings[i+1] == strings[i]) {
				s.push(1);
				cnt++;
				sum++;
			}
			else {
				sum += cnt;
				i++;
			}
		}
		else {
			if(!s.empty()) {
				s.pop();
				cnt--;
			}
		}
	}
	
	printf("%d\n", sum);
}