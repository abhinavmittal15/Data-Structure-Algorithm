// Link : https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findFloor(vector<long long> arr, long long n, long long x) {

        int s = 0;
        int e = n-1;
        int ans = 0;
        while(s <= e){
            int m = s + (e - s)/2;
            if(arr[m] >= x){
                e = m - 1;
                ans = m;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<long long> arr = {1, 2, 8, 10, 11, 12, 19};
    long long n = 7;
    long long x = 0;
    cout << s.findFloor(arr, n, x) << endl;
    return 0;
}