//Link to this problem : https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include<iostream>
#include<stack>

using namespace std;

class Solution{
public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        stack<char> temp;
        for(int i=0; i<x.length(); i++){
            if(temp.empty()){
                temp.push(x[i]);
            }
            else if((temp.top() == '(' && x[i] == ')') ||
                    (temp.top() == '{' && x[i] == '}') ||
                    (temp.top() == '[' && x[i] == ']')){
                temp.pop();    
            }
            else{
                temp.push(x[i]);
            }
        }
        if(temp.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    int t;
    string a;
    cin >> t;
    while(t--){
        cin >> a;
        Solution obj;
        if(obj.ispar(a)){
            cout << "balanced" << endl;
        }
        else{
            cout << "not balanced" << endl;
        }
    }
}
