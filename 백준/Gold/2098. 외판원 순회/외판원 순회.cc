#include <bits/stdc++.h>
using namespace std;
#define MAX_N 16
const int INF = 987654321;
int n, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int tsp(int here, int visited){
    // 모든 지점을 방문했다면 즉 dist[here][0]이 있다면 (마지막 지점에서 출발 지점으로 가는 거리가 있으면)
    // dist[here][0]을 반환하고, 그렇지 않다면 INF 반환
    // INF 반환: 돌아오는 길이 없으면 배제시켜야 하는데, 이 문제는 최솟값을 구하는 문제이므로 INF 반환
    if (visited == (1 << n) - 1){
        return dist[here][0] ? dist[here][0] : INF;
    }
    
    int &ret = dp[here][visited];
    if (ret != -1) return ret;
    ret = INF; // 최솟값은 최대값부터 시작한다
    
    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue;
        if(dist[here][i] == 0) continue;
        ret = min(ret, tsp(i, visited | (1 << i)) + dist[here][i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n';
    return 0;
}

/**
 * 도시의 수 N이 주어진다. (2 ≤ N ≤ 16) 
   순서가 상관이 있다면 16! (16 Factorial) 인데
   순서 상관없이 최솟값을 구하면 되므로 부분최적해를 사용하는, DP 문제이다
 
 * 비트를 사용하면, 
   상태값(포함하느냐 포함하지 않느냐) 에 대한 boolean 배열을 만들 때
   [][][]... 다차원(여기서는 16차원)의 배열의 사용하는 대신에 하나의 숫자로 나타낼 수 있다
   나는 visited 정수를 사용하기로 정했다.
   
 * 출발 지점이 명시되어있지 않다.
   2312 이나 3123 이나 같다. 2에서 시작하나 3에서 시작하나 경로는 같기 때문.
   나는 1번 지점부터 시작하기로 정했다. (코드에서는 1번을 0번으로)
 
 * here 는 인덱스이다. (1번 지점, 2번 지점, ...) 
 */