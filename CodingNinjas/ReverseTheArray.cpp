// The link to the problem : https://www.naukri.com/code360/problems/reverse-the-array_1262298

#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr , int m){
    int i = m+1;
    int j = arr.size() - 1;
    while(i<j){
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int m = 3;
    reverseArray(arr, m);
    for(int i = 0 ; i < arr.size() ; i++)
        cout<<arr[i]<<" ";
    return 0;

}