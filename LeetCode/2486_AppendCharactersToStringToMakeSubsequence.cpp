#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t){
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                j++;
            }
            i++;
        }
        return j == t.size() ? 0 : t.size() - j;
    }
};

int main(){
    Solution sol;
    string s = "coaching";
    string t = "coding";
    cout << sol.appendCharacters(s , t) << endl;
    return 0;
}