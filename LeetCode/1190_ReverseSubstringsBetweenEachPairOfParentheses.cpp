#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                // if(!st.empty()){

                // }
                int start = st.top();
                st.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        s.erase(remove(s.begin(), s.end(), '('), s.end());
        s.erase(remove(s.begin(), s.end(), ')'), s.end());
        return s;
    }
};

int main(){
    Solution sol;
    string s = "(ed(et(oc))el)";
    cout << sol.reverseParentheses(s) << endl;
    return 0;
}