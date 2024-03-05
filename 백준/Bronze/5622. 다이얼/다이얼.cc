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
	int array[10] = {0, };
	array[2] = 'A';
	array[3] = 'D';
	array[4] = 'G';
	array[5] = 'J';
	array[6] = 'M';
	array[7] = 'P';
	array[8] = 'T';
	array[9] = 'W';
	
	char a;
	int sum = 0;
	while((a=getchar())!='\n') {
		int i;
		for(i=0; (int)a >= array[i] && i<=9; i++) {}
		sum += i;
	}
	
	printf("%d\n", sum);
}