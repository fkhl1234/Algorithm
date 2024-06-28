#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;


int main() {
    int cnt = 0;
    int N, K;
    scanf("%d %d", &N, &K);

    queue<int> BFS;
    bool visit[100001] = {0, };
    BFS.push(N);
    visit[N] = true;
    int i;

    if(N==K) {
        printf("0\n");
        return 0;
    }
    for(i=1; ; i++) {
        queue<int> temp;

        while(!BFS.empty()) {
            int top = BFS.front();
            BFS.pop();

            if(top-1 == K) {temp.push(top-1); break;}
            else if(top-1>0 && !visit[top-1]) {
                visit[top-1] = true;
                temp.push(top-1);
            }

            if(top+1 == K ) {temp.push(top+1); break;}
            else if(top+1>0 && top+1 <= 100000 && !visit[top+1]) {
                visit[top+1] = true;
                temp.push(top+1);
            }

            if(top*2 == K) {temp.push(top*2); break;}
            else if(top*2>0 && top*2 <= 100000 && !visit[top*2]) {
                visit[top*2] = true;
                temp.push(top*2);
            }
        }

        if(temp.back() == K) break;
        else {
            while(!temp.empty()) {
                int t = temp.front();
                temp.pop();
                BFS.push(t);
            }
        }

    } // i is index of BFS

    printf("%d\n", i);

    return 0;
}
