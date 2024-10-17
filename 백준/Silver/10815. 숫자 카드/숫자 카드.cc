#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void solve(int n);
void solve(vector<int>& mine, vector<int>& card);

int binary_search(vector<int>& pool, int target, int start, int end);

int main() {
     int n;
     scanf("%d", &n);

     vector<int> mine;
     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);
          mine.push_back(temp);
     }

     scanf("%d", &n);

     vector<int> card;
     for(int i=0; i<n; i++) {
          int temp;
          scanf("%d", &temp);
          card.push_back(temp);
     }
     
     solve(mine, card);

     return 0;
}

void solve(vector<int>& mine, vector<int>& card) {
     sort(mine.begin(), mine.end());

     for(auto x: card) {
          int index = binary_search(mine, x, 0, mine.end()-mine.begin()-1);

          if(index!=-1) printf("1 ");
          else printf("0 ");
     }
     
     return;
}

int binary_search(vector<int>& pool, int target, int start, int end) {
     if(start>=end){
          if(pool[start]==target) return start;
          else return -1;
     }

     int re;

     if(pool[(start+end)/2]==target) return (start+end)/2;
     else if(pool[(start+end)/2]>target) re = binary_search(pool, target, start, (start+end)/2-1);
     else re = binary_search(pool, target, (start+end)/2+1, end);

     return re;
}