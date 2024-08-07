#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        vector<int> ages;
        for(int i=0; i<details.size(); i++){
            int age = stoi(details[i].substr(11, 2));
            ages.push_back(age);
        }
        int count = 0;
        for(int i=0; i<ages.size(); i++){
            if(ages[i] > 60){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout<<s.countSeniors(details)<<endl;
    return 0;
}