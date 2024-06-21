#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes){
        int l = 0;
        int curr_window = 0;
        int max_window = 0;
        int satisfied = 0;

        for(int r = 0; r < customers.size(); r++){
            if(grumpy[r] == 1){
                curr_window += customers[r];  //if owner is grumpy add customer to current window
            }
            else if(grumpy[r] == 0){       
                satisfied += customers[r];  //if owner is not grumpy add customer to satisfied 
            }
            if((r - l + 1) > minutes){
                if(grumpy[l] == 1){
                    curr_window -= customers[l];
                }
                l++;
            }
            max_window = max(curr_window, max_window);
        }
        return satisfied + max_window;
    }
};

int main(){
    Solution sol;
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    cout << sol.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}