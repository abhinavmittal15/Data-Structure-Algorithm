#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        for(int i : arr) {
            int remainder = ((i % k) + k) % k;
            remainderCount[remainder]++;
        }
        for (int i = 1; i < k; ++i) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }
        return remainderCount[0] % 2 == 0;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k = 5;
    cout << obj.canArrange(arr, k) << endl;
    return 0;
}