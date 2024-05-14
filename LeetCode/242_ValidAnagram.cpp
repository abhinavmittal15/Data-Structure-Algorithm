#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if( s == t )
            return true;
        return false;
    }
};

int main(){
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << s.isAnagram(s1, s2) << endl;
    return 0;
}