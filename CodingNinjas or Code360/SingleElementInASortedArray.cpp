//Link : https://www.naukri.com/code360/problems/unique-element-in-sorted-array_1112654

#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();

	if(n == 1){
		return arr[0];
	}

	if(arr[0] != arr[1]){
		return arr[0];
	}
	if(arr[n-1] != arr[n-2]){
		return arr[n-1];
	}

	int s = 1;
	int e = n-2;

	while(s <= e){
		int m = s + (e - s)/ 2;
		if(arr[m] != arr[m-1] && arr[m] != arr[m+1]){
			return arr[m];
		}
		else if((m%2==1 && arr[m] == arr[m-1]) || (m%2==0 && arr[m] == arr[m+1])){
			s = m + 1;
		}
		else{
			e = m - 1;
		}
	}
	return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << singleNonDuplicate(arr) << endl;
    return 0;
}