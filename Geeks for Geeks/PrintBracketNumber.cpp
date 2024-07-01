// Link : https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> bracketNumbers(string str) {
        int n = str.length();
        int count = 0;
        stack<int> st;
        vector<int> result;
        for(int i=0; i<n; i++){
            if(str[i] == '('){
                count++;
                st.push(count);
                result.push_back(count);
            }
            else if(str[i] == ')'){
                result.push_back(st.top());
                st.pop();

            }
        }
        return result;
    }
};

int main(){
    Solution s;
    string str = "(aa(bdc))p(dee)";
    vector<int> ans = s.bracketNumbers(str);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}