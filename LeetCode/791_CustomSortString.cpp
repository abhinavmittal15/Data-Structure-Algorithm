#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> s_counts;
        for(char c : s) {
            s_counts[c]++;
        }

        string result = "";
        for(char c : order) {
            if(s_counts.count(c)) {
                result.append(s_counts[c], c);
                s_counts.erase(c);
            }
        }

        for(auto& pair : s_counts) {
            result.append(pair.second, pair.first);
        }

        return result;
    }
};

int main(){
    Solution s;
    cout << s.customSortString("cba", "abcd") << endl;
    return 0;
}