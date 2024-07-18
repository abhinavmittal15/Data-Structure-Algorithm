// Link : https://www.naukri.com/code360/problems/lower-bound_8165382

#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	int s = 0;
	int e = n-1;
	int ans = n;
	while(s <= e){
		int m = s + (e-s)/2;
		if(arr[m] >= x){
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
    vector<int> arr = {1, 2, 2, 3, 3, 5};
    int n = 6;
    int x = 0;
    cout << lowerBound(arr, n, x) << endl;
    return 0;
}