#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for(int i= n-1; i >= 0; i--) {
            int digit = num[i] - '0';
            if(digit % 2 == 1) {
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};

int main() {
    Solution obj;
    string num = "10133890";
    cout << obj.largestOddNumber(num) << endl;
    return 0;
}