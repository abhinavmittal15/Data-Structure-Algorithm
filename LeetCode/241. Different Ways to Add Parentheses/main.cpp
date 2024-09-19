#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i=0; i<expression.length(); i++) {
            if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
                string a = expression.substr(0, i);
                string b = expression.substr(i+1);
                vector<int> al = diffWaysToCompute(a);
                vector<int> bl = diffWaysToCompute(b);
                for(int x : al) {
                    for(int y : bl) {
                        if(expression[i] == '-') {
                            res.push_back(x-y);
                        }
                        else if(expression[i] == '+') {
                            res.push_back(x+y);
                        }
                        else if(expression[i] == '*') {
                            res.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(res.size() == 0) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};

int main() {
    Solution obj;
    string expression = "2*3-4*5"; 
    vector<int> res = obj.diffWaysToCompute(expression);
    for(auto r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}