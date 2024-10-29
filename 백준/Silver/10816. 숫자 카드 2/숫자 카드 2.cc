#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
     int n, m;
     scanf("%d", &n);

     vector<int> card;
     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);

          card.push_back(temp);
     }
     sort(card.begin(), card.end());

     scanf("%d", &m);

     vector<int> target;
     for(int i=0; i<m; i++) {
          int temp;
          scanf("%d", &temp);

          target.push_back(temp);
     }

     for(int i=0; i<m; i++) {
          int num = target[i];

          int index = lower_bound(card.begin(), card.end(), target[i]) - card.begin();

          if(card[index]==target[i]) {
               int next_index = upper_bound(card.begin(), card.end(), target[i]) - card.begin();

               printf("%d ", next_index-index);
          }
          else printf("0 ");
     }

     return 0;
}