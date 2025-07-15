#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    string exp;
    cin >> exp;

    // string에서 첫번째 - 연산자 위치 기록 : 이후 숫자는 모두 빼면 그만
    size_t pos = exp.find("-", 0);
    if(pos==string::npos) pos = exp.length();

    // - 연산자 이전의 합
    size_t oper = 0;
    int sum1 = 0;
    for(int i=0; i<=pos; i++) {
        if(exp[i]=='+' || i==pos) {
            sum1 += stoi(exp.substr(oper, i-oper));
            oper = i+1;
        }
    }

    // - 연산자 이후의 합
    int sum2 = 0;
    oper = pos+1;
    for(int i = pos + 1; i <= exp.length(); i++) {
        if(i == exp.length() || exp[i] == '+' || exp[i] == '-') {
            sum2 += stoi(exp.substr(oper, i - oper));
            oper = i + 1;
        }
    }

    cout << sum1 - sum2 << endl;

    return 0;
}
