//Link to the problem : https://www.naukri.com/code360/problems/valid-parenthesis_795104

#include<iostream>
#include<stack>

using namespace std;

bool isValidParenthesis(string s){
    stack<char> temp;
    for(int i=0 ; i<s.length(); i++){
        if(temp.empty()){
            //if the stack is empty then add the current parenthesis to the stack
            temp.push(s[i]);
        }
        else if ((temp.top() == '(' && s[i] == ')') ||
                (temp.top() == '{' && s[i] == '}') ||
                (temp.top() == '[' && s[i] == ']')){
            temp.pop();
        }
        else{
            temp.push(s[i]);
        }
    }
    if(temp.empty()){
        return true;
    }
    return false;
}

int main(){
    string s = "[()]{}{[()()]()}";
    cout << isValidParenthesis(s) << endl;
    return 0;
}