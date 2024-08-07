#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){

        if(s.length() != t.length()) return false;

        vector<int> s_map(256, -1); // 256 ASCII characters
        vector<int> t_map(256, -1); // 256 ASCII characters

        for(int i = 0; i < s.length(); i++){
            if(s_map[s[i]] != t_map[t[i]]) return false;
            s_map[s[i]] = i;
            t_map[t[i]] = i;
        }
        return true;
    }
};

int main(){
    Solution S;
    string s = "egg";
    string t = "add";
    cout << S.isIsomorphic(s, t) << endl;
}