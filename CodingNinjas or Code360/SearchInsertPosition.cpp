// Link : https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& arr, int x){
    int n = arr.size();
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
    int x = 0;
    cout << searchInsert(arr, x) << endl;
    return 0;
}