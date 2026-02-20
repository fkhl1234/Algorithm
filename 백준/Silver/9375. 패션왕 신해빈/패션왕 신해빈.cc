#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <unordered_map>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    // testcase loop
    for(int t=0; t<T; t++) {
        int n;
        scanf("%d", &n);
        cin.ignore();

        unordered_map<string, int> dict;
        for(int i=0; i<n; i++) {
            string str;
            getline(cin, str);

            stringstream ss(str);
            string value, type;
            ss >> value >> type;
            
            if(dict.find(type) == dict.end()) {
                dict[type] = 1;
            } else {
                dict[type] += 1;
            }
        } 

        int total = 1;
        for(auto i = dict.begin(); i!=dict.end(); i++) {
            // printf("%s: %d\n", (*i).first.c_str(), (*i).second);
            total *= ((*i).second + 1);
        }

        printf("%d\n", total-1);
    }


    return 0;
}