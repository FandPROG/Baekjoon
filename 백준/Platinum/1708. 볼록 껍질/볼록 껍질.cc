#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
using ll = long long;

ll n;
ll Bx = 2e9, By = 2e9; // 기준점 x, y

struct dat {
    ll x, y;
};

// ccw 계산 함수
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if(cross < 0) return -1;
    if(cross == 0) return 0;
    else return 1;
}

// 거리 계산 함수
ll dis(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// 정렬 기준
bool comp(dat a, dat b) {
    ll ccw_val = ccw(Bx, By, a.x, a.y, b.x, b.y);
    if(ccw_val == 0) 
        return dis(Bx, By, a.x, a.y) < dis(Bx, By, b.x, b.y);
    return ccw_val > 0;
}

int main() {
    vector<dat> vec;

    // 입력 받기
    scanf("%lld", &n);

    for (ll i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        vec.push_back({x, y});
        if (y < By || (y == By && x < Bx)) {
            By = y;
            Bx = x;
        }
    }

    // 정렬
    sort(vec.begin(), vec.end(), comp);

    // 스택 초기화
    vector<dat> st;
    st.push_back({Bx, By});  // 기준점 추가
    st.push_back(vec[0]);     // 첫 번째 점 추가

    // 그라함 스캔 알고리즘
    for (ll i = 1; i < vec.size(); i++) {
        while (st.size() >= 2) {
            dat fir = st[st.size() - 2];
            dat sec = st[st.size() - 1];
            if (ccw(fir.x, fir.y, sec.x, sec.y, vec[i].x, vec[i].y) > 0) {
                break;
            }
            st.pop_back();
        }
        st.push_back(vec[i]);
    }

    // 결과 출력 (점의 개수)
    printf("%zu", st.size());  // size_t로 출력
    return 0;
}
