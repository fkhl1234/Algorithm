#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <deque>

using namespace std;

int main() {   
     int n;
     scanf("%d", &n);
     
     deque<int> card;
     for(int i=1; i<=n; i++) {
          card.push_back(i);
     }

     while(card.size()>1) {
          card.pop_front();

          int temp = card.front();
          card.pop_front();
          card.push_back(temp);
     }

     printf("%d\n", card.front());
}