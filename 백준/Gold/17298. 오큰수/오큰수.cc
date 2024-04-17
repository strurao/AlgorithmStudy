#include <bits/stdc++.h>
using namespace std; 
int n, a[1000004], ret[1000004];
stack<int> s; 
int main(){
	cin >> n; 
	memset(ret, -1, sizeof(ret));
	for(int i = 0; i < n; i++){
		cin >> a[i];  
		while(s.size() && a[s.top()] < a[i]){
			ret[s.top()] = a[i]; s.pop();
		}
		s.push(i);
	}
	for(int i = 0; i < n; i++) cout << ret[i] << " ";  
} 
/**
 * 짝짓기 문제는 스택을 생각해보자
 * 스택에 담아놓다가, 어떤 조건을 통과하여 결정이 되면 그때 오큰수를 ret에 담기
 * ret 배열 ?
 */