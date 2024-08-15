//Link to problem : https://www.geeksforgeeks.org/problems/insertion-sort/0

#include<iostream>

using namespace std;

class Solution
{
public:
    void insertionSort(int arr[], int n)
    {
        for(int i=0; i<n; i++)
        {
            int j=i;
            while(j>0 && arr[j-1]>arr[j])
            {
                swap(arr[j], arr[j-1]);
                j--;
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
    obj.insertionSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}