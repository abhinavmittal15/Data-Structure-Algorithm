#include<iostream>
#include<string>
using namespace std;

                        //This solution can also be used
// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         size_t pos = s.find(part);
//         while(pos!= string::npos){
//             s.erase(pos, part.length());
//             pos = s.find(part);
//         }
//         return s;
//     }
// };
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part),  part.length());
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << sol.removeOccurrences(s, part) << endl;
    return 0;
}