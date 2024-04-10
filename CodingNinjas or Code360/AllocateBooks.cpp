// The link to the problem:- https://www.codingninjas.com/studio/problems/allocate-books_1090540

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid){
    if(m>n){
        return false;
    }
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
        if(studentCount > m){
            return false;
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    int s=0;
    int sum =0;

    for(int i=0 ; i<n ; i++){
        sum += arr[i];
    }
    int e= sum;
    int ans =-1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e= mid -1;
        }
        else{
            s= mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    cout << findPages(arr, n, m) << endl;
    return 0;
}