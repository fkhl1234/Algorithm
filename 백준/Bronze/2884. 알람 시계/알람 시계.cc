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
	int h, m;
	scanf("%d %d", &h, &m);
	
	if(m<45){
		m = 15+m;
		if(h!=0) h--;
		else h = 23;
	}
	else m-=45;
	
	printf("%d %d\n", h, m);
}