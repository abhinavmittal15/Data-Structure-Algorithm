#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        for (int i = 0; i + 1 < number.length(); ++i)
            if (number[i] == digit && digit < number[i + 1])
                return number.erase(i, 1);
        return number.erase(number.rfind(digit), 1);
    }
};

int main(){
    Solution s;
    string number = "133235";
    char digit = '3';
    cout << s.removeDigit(number, digit) << endl;
    return 0;
}