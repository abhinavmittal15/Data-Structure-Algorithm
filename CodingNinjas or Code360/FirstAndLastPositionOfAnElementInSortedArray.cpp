// Link : https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

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

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}