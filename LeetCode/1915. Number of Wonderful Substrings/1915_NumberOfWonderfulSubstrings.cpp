#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word){
        vector<long long> count(1024);
        count[0] = 1;
        int mask = 0;
        long long res = 0;
        for(int i=0; i<word.size(); i++){
            mask ^= 1<<(word[i]- 'a');
            res += count[mask];
            for(int j=0; j<10; j++){
                res += count[mask ^ (1 << j)];
            }
            count[mask]++;
        }
        return res;
    }
};

int main(){
    Solution s;
    string word = "aba";
    cout<<s.wonderfulSubstrings(word)<<endl;
    return 0;
}