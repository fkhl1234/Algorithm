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
	int score;
	scanf("%d", &score);
	
	if(score>=90) printf("A\n");
	else if(score>=80) printf("B\n");
	else if(score>=70) printf("C\n");
	else if(score>=60) printf("D\n");
	else printf("F\n");
}