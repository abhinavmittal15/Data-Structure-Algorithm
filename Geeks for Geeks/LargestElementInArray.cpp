// Link : https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        return *max_element(arr.begin(), arr.end());
    }
};

int main(){
    Solution s;
    vector<int> arr= {1, 8, 7, 56, 90};
    int n = 5;
    cout << s.largest(arr, n) << endl;
    return 0;
}