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
	int num;
	scanf("%d", &num);
	
	int sum = num * (num+1) / 2;
	printf("%d", sum);
}