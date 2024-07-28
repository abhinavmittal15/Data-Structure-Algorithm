//Link : https://www.naukri.com/code360/problems/find-peak-element_1081482

#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if(n == 1){
        return 0;
    }
    if(arr[0] > arr[1]){
        return 0;
    }
    if(arr[n-1] > arr[n-2]){
        return n-1;
    }

    int s = 1;
    int e = n-2;
    while(s <= e){
        int m = s + (e - s)/ 2;
        if(arr[m] > arr[m-1] && arr[m] > arr[m+1]){
            return m;
        }
        else if(arr[m] > arr[m-1]){
            s = m + 1;
        }
        else if(arr[m] > arr[m+1]){
            e = m - 1;
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
    cout << findPeakElement(arr) << endl;
    return 0;
}