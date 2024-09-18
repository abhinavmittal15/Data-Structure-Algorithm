#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numString;
        for(int num : nums) {
            numString.push_back(to_string(num));
        }
        sort(numString.begin(), numString.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if(numString[0] == "0") {
            return "0";
        }
        string ans = "";
        for(const string& num : numString) {
            ans = ans + num;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {3,30,34,5,9};
    cout << obj.largestNumber(nums) << endl;
    return 0;
}