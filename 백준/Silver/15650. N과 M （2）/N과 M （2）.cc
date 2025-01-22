#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

vector<int> st;
int n, m;
void DFS(int start, int n, int cnt);
bool visit[9] = {0, };

int main() {
     // basic setting
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     // code
     cin >> n >> m;
     
     DFS(1, n, m);

     return 0;
}

void DFS(int start, int n, int cnt) {
    if (cnt == 0) { // 조합이 완성되면 출력
        for (auto x : st) {
          printf("%d ", x);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++) { // `start`부터 탐색
        st.push_back(i);        // 숫자 선택
        DFS(i + 1, n, cnt - 1); // 다음 숫자로 진행
        st.pop_back();          // 복원
    }
}
