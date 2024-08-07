#include<iostream>
using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            int newPos = (i + k) % n;
            res.append(1, s[newPos]);
        }
        return res;
    }
};

int main(){
    Solution s;
    string str = "oxoq";
    int k = 4;
    cout << s.getEncryptedString(str, k) << endl;
    return 0;
}