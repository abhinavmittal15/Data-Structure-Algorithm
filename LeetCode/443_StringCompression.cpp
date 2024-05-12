#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int ansIndex = 0;
        int i = 0;
        int n = chars.size();
        while(i < n){
            int j = i+1; 
            while(j < n && chars[i] == chars[j]){
                j++;
            }
            chars[ansIndex++] = chars[i];
            int count = j-i;
            if(count > 1){
                string cnt = to_string(count);
                for(char ch: cnt){
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }
};

int main(){
    Solution s;
    vector<int> chars = {"a","a","b","b","c","c","c"};
    cout << s.compress(chars) << endl;
    return 0;
}