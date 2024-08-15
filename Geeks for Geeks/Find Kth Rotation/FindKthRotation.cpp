// Link : https://www.geeksforgeeks.org/problems/rotation4723/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            //if it is already sorted
            if(arr[s] <=arr[e]){
                return s;
            }
            
            int m = s + (e-s)/2;
            
            if((m == 0 || arr[m] < arr[m-1]) && (m == n - 1 || arr[m] < arr[m + 1]) ){
                return m;
            }
            
            
            if(arr[s] <= arr[m]){
                s = m + 1;    
            }
            else{
                e = m - 1;
            }
        }
        return 0;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {5, 1, 2, 3, 4};
    cout << obj.findKRotation(arr) << endl;
    return 0;

}