#include<bits/stdc++.h>
using namespace std;
int dp[1004][2][34], n, m, b[1004];

int go(int idx, int tree, int cnt){
    // 기저사례
    if (cnt < 0) return -1e9;
    if (idx == n) return cnt == 0? 0: -1e9;
    
    // 메모이제이션
    int &ret = dp[idx][tree][cnt];
    if (~ret) return ret; // 초기값 -1이 아니면 값 반환 
    
    // 로직
    return ret = max(go(idx+1, tree^1, cnt-1), go(idx+1, tree, cnt)) + (tree == b[idx]-1);
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> b[i];
    cout << max(go(0,1,m-1), go(0,0,m)) << '\n';
    return 0;
}

/**
 * 완전탐색으로 풀이 시 2^30으로 경우의 수가 급증한다. DP를 떠올리자
 
 * 문제의 상태값은 3개다. 
 * (1) T (1≤T≤1,000)
 * (2) W (1≤W≤30)
 * (3) 나무의 번호 1 또는 2 (움직이거나 안움직이거나)
 
 * DP 구조 4가지
 * (1) 기저사례
       * 이 문제는 최대값을 구하는 것이므로 여기서 -1e9를 반환하는 것도 기저사례로 OK
 * (2) 메모이제이션
       * ~ = -(n+1)
 * (3) 로직
 * (4) 초기화
       * 결과값의 후보가 아닌 -1 으로 초기화
 */