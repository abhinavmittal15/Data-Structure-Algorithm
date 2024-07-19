//Link : https://www.naukri.com/code360/problems/implement-upper-bound_8165383

#include<iostream>
#include<vector>
using namespace std;

int upperBound(vector<int> &arr, int x, int n){
	int s = 0;
	int e = n-1;
	int ans = n;
	while(s <= e){
		int m = s + (e-s)/2;
		if(arr[m] > x){
			ans = m;
			e = m - 1;
		}
		else{
			s = m + 1;
		}
	}
	return ans;
}

int main(){
    vector<int> arr = {2, 4, 6, 7};
    int x = 5;
    int n = 4;
    cout << upperBound(arr, x, n) << endl;
    return 0;
}