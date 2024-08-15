// Link : https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:	
	int count(int arr[], int n, int x) {
	    vector<int> nums(arr, arr + n);
    	pair<int, int> ans =  firstAndLastPosition(nums, n, x);
    	if(ans.first == -1){
    		return 0;
    	}
    	return ans.second - ans.first + 1;
	}
private:
    int lowerBound(vector<int> arr, int n, int k){
        int s = 0;
        int e = n-1;
        int ans = n;
        while(s <= e){
            int m = s + (e-s)/2;
            if(arr[m] >= k){
                e = m - 1;
                ans = m;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }
    
    int upperBound(vector<int> arr, int n, int k){
        int s = 0;
        int e = n-1;
        int ans = n;
        while(s <= e){
            int m = s + (e-s)/2;
            if(arr[m] > k){
                e = m - 1;
                ans = m;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }
    
    pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
        int lb = lowerBound(arr, n, k);
        if(lb == n || arr[lb] != k){
            return {-1, -1};
        }
        int ub = upperBound(arr, n, k);
        return {lb, ub - 1};
        
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    int x;
    cin >> x;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << obj.count(arr, n, x) << endl;
    return 0;
}