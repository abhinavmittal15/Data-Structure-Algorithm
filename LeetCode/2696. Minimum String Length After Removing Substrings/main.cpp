#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        for(int i=0; i<s.length()-1; i++) {
            if(s.substr(i, 2) == "AB" || s.substr(i, 2) == "CD") {
                s = s.substr(0, i) + s.substr(i+2);
                i = -1;
            }
        }
        return s.length();
    }
};

int main() {
    Solution obj;
    string s;
    cin >> s;
    cout << obj.minLength(s) << endl;
    return 0;
}