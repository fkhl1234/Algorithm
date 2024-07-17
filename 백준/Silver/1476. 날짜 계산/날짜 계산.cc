#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int e, s, m;
    scanf("%d %d %d", &e, &s, &m); // input

    int te = 1, ts = 1, tm = 1;
    int year = 1;

    while(e!=te || s!=ts || m!=tm) {
        year++;

        te++;
        ts++;
        tm++;

        if(te>15) te = 1;
        if(ts>28) ts = 1;
        if(tm>19) tm = 1;
    }

    printf("%d\n", year);

    return 0;
}
