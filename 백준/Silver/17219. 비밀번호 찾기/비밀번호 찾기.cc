#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct password {
    char site[21];
    char pw[21];
};

vector<password> dict;

void binary_search(char* str, int start, int end) {
    if(start > end) return;

    int mid = (start + end) / 2;

    if(strcmp(str, dict[mid].site) < 0) {
        binary_search(str, start, mid-1);
    } else if (strcmp(str, dict[mid].site) > 0) {
        binary_search(str, mid+1, end);
    } else {
        printf("%s\n", dict[mid].pw);
        return; 
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);


    for(int i=0; i<n; i++) {
        password temp;

        scanf("%s", temp.site);
        scanf("%s", temp.pw);

        dict.push_back(temp);
    }

    sort(dict.begin(), dict.end(), [](password a, password b) {
        return strcmp(a.site, b.site) < 0;
    });

    // printf("check\n");

    // for(int i=0; i<n; i++) {
    //     printf("%s : %s\n", dict[i].site, dict[i].pw);
    // }

    for(int i=0; i<m; i++) {
        char temp[21];
        scanf("%s", temp);

        binary_search(temp, 0, n-1);
    }

    return 0;
}