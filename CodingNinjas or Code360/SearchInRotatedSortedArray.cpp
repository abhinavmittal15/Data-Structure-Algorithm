#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>& arr, int n){
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid+ 1;
        }
        else{
            e= mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key){
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid= s+(e-s)/2;
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if(arr[pivot] <= k && k <= arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    }
    else{
        return binarySearch(arr, 0, pivot - 1, k);
    }
    return -1;
    // Write your code here.
    // Return the position of K in ARR else return -1.
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int n = arr.size();
    int k = 0;
    cout<<search(arr, n, k);
    return 0;
}