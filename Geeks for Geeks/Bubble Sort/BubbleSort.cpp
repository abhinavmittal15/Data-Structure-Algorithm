//Link to the problem : https://www.geeksforgeeks.org/problems/bubble-sort/1

#include<iostream>

using namespace std;

class Solution {
  public:
    void bubbleSort(int arr[], int n) {
        for(int i=n-1; i>=0; i--){
            for(int j=0; j< i; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Solution obj;
    obj.bubbleSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}