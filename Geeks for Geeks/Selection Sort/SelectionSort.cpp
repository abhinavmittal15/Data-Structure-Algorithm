//Link to problem : https://www.geeksforgeeks.org/problems/selection-sort/1

#include<iostream>
using namespace std;

class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
        for(int i=0; i< n - 1; i++){
            int mini = i;
            for(int j=i+1; j<n ; j++){
                if(arr[j] < arr[mini] ){
                    mini = j;
                }
            }
            swap(arr[mini], arr[i]);
        }
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution ob;
    ob.selectionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}