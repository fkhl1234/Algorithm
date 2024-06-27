#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool visit[101] = {0, }; // visit check
vector<int> graph[101]; // vector to store connections of PC

void graph_search(int num);

int main() {
    int num;
    scanf("%d", &num); // number of PC

    int connection;
    scanf("%d", &connection);

    for(int i=0; i<connection; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    } // connect

    graph_search(1);

    int cnt = 0; // the number of infected PC
    for(int i=2; i<=num; i++) {
        if(visit[i]) cnt++;
    } // check the number of infected

    printf("%d", cnt);
}

void graph_search(int num) {
    if(!visit[num]) {
        visit[num] = true; //PC x is visited

        for(auto x:graph[num]) {
            graph_search(x); //recursive
        }
    } // if this PC is not visited
}