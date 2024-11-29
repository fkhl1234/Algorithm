#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>

using namespace std;

int main() {
     string input;

     while(1) {
          getline(cin, input);
          
          if(input[0] == '.') break;
          
          stack<int> parenthesis;
     
          bool balance = true;

          for(auto s: input) {
               if(s == '[') parenthesis.push(0);
               if(s == '(') parenthesis.push(1);
               
               
               if(s == ']') {
                    if(parenthesis.empty()) {
                         balance = false;
                         break;
                    }
                    if(parenthesis.top() != 0) {
                         balance = false;
                         break;
                    }
                    else parenthesis.pop();
               }
               if(s == ')') {
                    if(parenthesis.empty()) {
                         balance = false;
                         break;
                    }
                    if(parenthesis.top() != 1) {
                         balance = false;
                         break;
                    }
                    else parenthesis.pop();
               }
          }

          if(!parenthesis.empty()) {
               balance = false;
               while(!parenthesis.empty()) parenthesis.pop();
          } 

          if(balance) printf("yes\n");
          else printf("no\n");
     }
}
