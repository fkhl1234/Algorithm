#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

deque<int> deq;

void cmd_process(int& cmd);

int main() {   
     int n;
     scanf("%d", &n);

     for(int i=0; i<n; i++) {
          int cmd;
          scanf("%d", &cmd);

          cmd_process(cmd);
     }
}

void cmd_process(int& cmd) {
     int x;
     int size;

     switch(cmd) {
          case 1:
               scanf("%d", &x);
               deq.push_front(x);               

               break;
          case 2:
               scanf("%d", &x);
               deq.push_back(x);

               break;
          case 3:
               if(deq.empty()) {
                    printf("-1\n");
               }
               else {
                    int temp = deq.front();
                    deq.pop_front();
                    printf("%d\n", temp);
               }
               break;
          case 4:
               if(deq.empty()) {
                    printf("-1\n");
               }
               else {
                    int temp = deq.back();
                    deq.pop_back();
                    printf("%d\n", temp);
               }
               break;
          case 5:
               size = deq.size();
               printf("%d\n", size);
               break;
          case 6:
               if(deq.empty()) printf("1\n");
               else printf("0\n");
               break;
          case 7:
               if(deq.empty()) {
                    printf("-1\n");
               }
               else {
                    int temp = deq.front();
                    printf("%d\n", temp);
               }
               break;
          case 8:
               if(deq.empty()) {
                    printf("-1\n");
               }
               else {
                    int temp = deq.back();
                    printf("%d\n", temp);
               }
               break;

          default:
               break;
     }
}