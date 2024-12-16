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

using namespace std;

int main() {   
     ios_base :: sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int n;
     cin >> n;
     
     queue<int> cmd;

     for(int i=0; i<n; i++) {
          string str;
          cin >> str;

          if(str=="push") {
               int temp;
               cin >> temp;

               cmd.push(temp);
          }
          else if(str=="pop") {
               if(cmd.empty()) {

                    printf("-1\n");
                    continue;
               }
               printf("%d\n", cmd.front());
               cmd.pop();
          }
          else if(str=="size") {
               printf("%d\n", cmd.size());
          }
          else if(str=="empty") {
               cmd.empty() ? printf("1\n") : printf("0\n");
          }
          else if(str=="front") {
               if(cmd.empty()) {
                    printf("-1\n");
                    continue;
               }

               printf("%d\n", cmd.front());
          }
          else if(str=="back") {
               if(cmd.empty()) {
                    printf("-1\n");
                    continue;
               }

               printf("%d\n", cmd.back());
          }
     }
}