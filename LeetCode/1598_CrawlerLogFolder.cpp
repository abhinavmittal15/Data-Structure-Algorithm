#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> main;
        for(int i=0; i<logs.size(); i++){
            if(logs[i] == "../"){  //means that it is of ../ form
                if(main.size() != 0){
                    main.pop();
                }
            }
            else if(logs[i] == "./"){  //means that it is of ./ form
                continue;  //do nothing
            }
            else{ // means it is of x/ type 
                main.push(logs[i]);
            }
        }
        return main.size();
    }
};

int main(){
    Solution sol;
    vector<string> logs = {"d1/","d2/","../","d21/","./"};
    cout << sol.minOperations(logs) << endl;
    return 0;
}