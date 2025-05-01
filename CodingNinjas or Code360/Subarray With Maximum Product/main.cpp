// Link : https://www.naukri.com/code360/problems/subarray-with-maximum-product_6890008

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int subarrayWithMaxProduct(vector<int> &arr){
	// int prod = 1;
	int s = 1;
    int e = 1;
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0; i<n; i++ ){ 
        if(s == 0) {
            s = 1;
        }
        if(e == 0)  {
            e =1;
        }
        s = s * arr[i];
        e = e * arr[n-i-1];
        maxi = max(maxi, max(s, e));
    }
	return maxi;
}

int main() {
    vector<int> arr = {-1, 3, 0, -4, 3};
    cout << subarrayWithMaxProduct(arr) << endl;
    return 0;
}