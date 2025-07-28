#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int G, P;
    scanf("%d %d", &G, &P);

    vector<int> gi(P);

    for(int i=0; i<P; i++) {
        scanf("%d", &gi[i]);
    }
    
    set<int> gate; // 게이트 인덱스
    for(int i=0; i<G; i++) {
        gate.insert(i+1);
    }

    int cnt = 0;
    // for(auto x: gi) {
    //     bool docking = false;

    //     auto it = gate.lower_bound(x);
    //     if(it!=gate.end()) {
    //         // 해당 인덱스 삭제            
    //         if(it==gate.begin()) {
    //             if(*it>x) break;
    //         }
    //         else {
    //             if(*it>x) --it;
    //         }
    //         gate.erase(it);

    //         cnt++;
    //         docking = true;
    //     }

    //     if(!docking) break;
    // }
    for(auto x : gi) {
        auto it = gate.upper_bound(x);  // x보다 큰 가장 작은 값
        if(it == gate.begin()) break;  // 도킹 불가
        
        --it;  // x 이하 중 가장 큰 게이트
        gate.erase(it);  // 도킹 완료
        cnt++;
    }


    printf("%d\n", cnt);

    return 0;
}
