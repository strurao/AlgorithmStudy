#include <vector>

using namespace std;

int answer = 0;

void get_solv_num(vector<int> numbers, int target, int sum, int idx){
    if(idx == numbers.size())
    {
        if(sum==target)
        {
            answer++;    
        }
        return;
    }
    get_solv_num(numbers, target, sum-numbers[idx], idx+1);
    get_solv_num(numbers, target, sum+numbers[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    get_solv_num(numbers, target, 0, 0);
    return answer;
}