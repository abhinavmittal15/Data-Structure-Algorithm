#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3)
            return false;

        for(int i=0; i<arr.size()-2; i++){
            if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    vector<int> arr2 = {1};
    cout << "arr 1 : "<< s.threeConsecutiveOdds(arr1) << endl;
    cout << "arr 2 : "<< s.threeConsecutiveOdds(arr2) << endl;
    return 0;
}