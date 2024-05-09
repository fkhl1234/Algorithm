#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	
	int zero;
	int ten=0;
	int five=0;
	for(int i=1; i<=n; i++) {
		int temp = i;
		if(i%10==0) {
			while(temp%10 == 0){
				ten++;
				temp/=10;
			}
		}
		if(i%5==0) {
			while(temp%5 == 0){
				five++;
				temp/=5;
			}
		}
	}
	
	cout << five + ten << endl;
}