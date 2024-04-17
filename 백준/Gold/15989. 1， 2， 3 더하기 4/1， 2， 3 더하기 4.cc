#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, dp[10001];

int main(){
    // 입력부
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t; // 테스트 케이스 수
    
    // 로직
    dp[0] = 1;
    for (int i=1; i<=3; i++){ // 더하는 수: 1,2,3
        for (int j=1; j<=10000; j++){
            if (j-i >= 0) 
                dp[j] += dp[j-i];
        }
    }
    
    // 출력부
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}

/**
 * 경우의 수 DP
 * 경우의 수는 다 더해버리면 된다 (?)
 
 * dp[n]: 합이 n이 되는 경우의 수
 */