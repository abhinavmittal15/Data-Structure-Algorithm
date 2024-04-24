#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start<end){
            swap(s[start++], s[end--]);
        }
    }
};

int main(){
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    for (auto c : str)cout<<c<<" ";
    return 0;
}