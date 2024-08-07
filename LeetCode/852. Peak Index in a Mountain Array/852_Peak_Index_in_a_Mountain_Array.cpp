#include<iostream>
#include<vector> // Add this line
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int e=arr.size() -1;
        int mid= s + (e-s)/2;
        while(s<e){
            if(arr[mid] < arr[mid + 1]){
                s= mid+ 1;
            }else{
                e=mid;
            }
            mid = s + (e - s)/2;
        }
        return e;
    }
};

int main(){
    vector<int> arr = {0,2,1,0};
    Solution s;
    cout<<s.peakIndexInMountainArray(arr);
    return 0;
}