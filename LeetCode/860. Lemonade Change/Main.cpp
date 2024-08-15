#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                fiveCount++;
            }
            else if(bills[i] == 10){
                tenCount++;
                if(fiveCount > 0){
                    fiveCount--;
                }
                else{
                    return false;
                }
            }
            else{
                if(tenCount > 0 && fiveCount > 0){
                    tenCount--;
                    fiveCount--;
                }
                else if(fiveCount >= 3){
                    fiveCount = fiveCount - 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution obj;
    vector<int> bills = {5,5,5,10,20};
    cout<<obj.lemonadeChange(bills)<<endl;
    return 0;
}