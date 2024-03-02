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
	int year;
	scanf("%d", &year);
	
	if(year%4==0 & year%100!=0) printf("1\n");
	else if(year%400==0) printf("1\n");
	else printf("0\n");
}