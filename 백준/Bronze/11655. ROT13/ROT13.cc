#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        // 소문자인 경우
        if(str[i] >= 'a' && str[i] <= 'z') // 97~122 (ASCII)
        {
            str[i] += 13;
            if(str[i] < 'a' || str[i] > 'z') str[i] -= 26; //?
        }
        // 대문자인 경우
        if(str[i] >= 'A' && str[i] <= 'Z') // 65~90
        {
            str[i] += 13;
            if(str[i] < 'A' || str[i] > 'Z') str[i] -= 26; //?
        }
        cout << str[i];
    }
    return 0;
}