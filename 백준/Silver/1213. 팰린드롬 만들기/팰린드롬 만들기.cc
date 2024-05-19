#include<bits/stdc++.h>
using namespace std;
string str, ret;
int cnt[200], flag;
char mid;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    
    for(char s : str)
        cnt[s]++; // 알파벳이 몇개인지
    
    for(int i = 'Z'; i >= 'A'; i--)
    {
        if(cnt[i])
        {
            if(cnt[i] & 1) // 홀수라면
            {
                mid = char(i); // 중간에 오도록 
                flag++;
                cnt[i]--;
            }
            
            if(flag == 2) // 홀수가 2개 이상이면 팰린드롬 불가
                break; // I'm Sorry Hansoo 로
            
            for(int j = 0; j < cnt[i]; j += 2)
            {
                // 앞뒤로 붙여주기 
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    
    if(mid) 
        ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag==2) 
        cout << "I'm Sorry Hansoo\n";
    else cout << ret << "\n";
}

// 팰린드롬을 만들 때 z부터 하도록 해야겠다! 원래 문자의 순서는 상관이 없다.
// 불가능하다면 Sorry를 출력, -> 홀수가 2개 이상인 경우
// 테스트 케이스가 생각이 안나면 작게작게 생각해보아요
// 아니면 아스키코드 순 오름차순인 펠림드롬을 만들어서 출력