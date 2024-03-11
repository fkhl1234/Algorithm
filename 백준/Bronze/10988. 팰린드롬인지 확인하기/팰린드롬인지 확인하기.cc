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
	char str[102];
	
	int index = 0;
	while((str[++index]=getchar())!='\n') {}
	index--;
	
	bool fact = true;
	for(int i=1; i<=index/2; i++) {
		if(str[i] != str[index-i+1]) {
			fact = false;
			break;
		} 
	}
	
	printf((fact)?"1\n":"0\n");
}