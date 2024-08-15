// Link : https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K){ 
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        for(int i=0; i<N; i++){
            sum = sum + A[i];
            if(sum == K){
                ans = max(ans, i+1);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            if(mp.find(sum-K) != mp.end()){
                ans = max(ans, i-mp[sum-K]);
            }
        }
        return ans;
    }
};

int main(){
    Solution ob;
    int N = 3;
    int K = 6;
    int A[] = {-1, 2, 3};
    cout << ob.lenOfLongSubarr(A, N, K) << endl;
    return 0;
}