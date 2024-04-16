/**
 * connected component 개수 찾기 (cnt개)
 * dfs
 */

#include<bits/stdc++.h>
using namespace std;
int a[101][101], visited[101][101], n, ret = 1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int depth){
    visited[y][x]=1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(!visited[ny][nx] && a[ny][nx] > depth) dfs(ny, nx, depth);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    for(int depth = 1; depth < 101; depth++){
        // 테스트 케이스 초기화 잊지말기
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        int cnt=0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > depth && !visited[i][j]){
                    dfs(i, j, depth);
                    cnt++;
                }
            }
        }
        
        // 최댓값 갱신
        ret = max(ret, cnt);
    }
    cout << ret << '\n';
    return 0;
}