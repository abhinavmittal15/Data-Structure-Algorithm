// Link : https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456

#include <bits/stdc++.h>
using namespace std;

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


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int lb = lowerBound(arr, n, k);
    if(lb == n || arr[lb] != k){
        return {-1, -1};
    }
    int ub = upperBound(arr, n, k);
    return {lb, ub - 1};
    
}

int count(vector<int>& arr, int n, int x) {
	pair<int, int> ans =  firstAndLastPosition(arr, n, x);
	if(ans.first == -1){
		return 0;
	}
	return ans.second - ans.first + 1;
}


int main(){
    int n = 7;
    int x = 3;
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3};
    cout << count(arr, n, x) << endl;
    return 0;
}