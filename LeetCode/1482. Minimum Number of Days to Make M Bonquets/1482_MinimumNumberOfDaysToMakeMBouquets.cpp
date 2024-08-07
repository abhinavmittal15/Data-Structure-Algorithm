#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    class Solution {
    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            int n = bloomDay.size();
            long long mk = static_cast<long long>(m) * k;
            if(mk > n) return -1;   //negative case
            int low = *min_element(bloomDay.begin(), bloomDay.end());
            int high = *max_element(bloomDay.begin(), bloomDay.end());
            int ans = high;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(isPossible(bloomDay, mid, m, k) == true){
                    ans = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            return ans;
        }
    private:
        bool isPossible(vector<int>& arr,int day, int m, int k){
            int count = 0;
            int noBokey = 0;
            for(int i=0; i<arr.size(); i++){
                if(arr[i] <= day){
                    count++;
                    if(count == k){
                        noBokey++;
                        count = 0;
                    }
                }
                else{
                    // noBokey += (count/k);
                    count = 0;
                }
            }
            // noBokey += (count/k);
            // if(noBokey >= m) return true;
            // else return false;
            return noBokey >= m;
        }
    };

int main(){
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;
    cout << sol.minDays(bloomDay, m, k) << endl;
    return 0;
}