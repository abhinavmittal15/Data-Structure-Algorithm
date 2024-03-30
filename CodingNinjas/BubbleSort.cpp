//Link to the problem : naukri.com/code360/problems/bubble-sort_980524

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1 ; i < n ; i++){
        bool swapped = false;
        for(int j=0 ; j < n-i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

int main(){
    int n = 5;
    vector<int> arr = {6 ,2 , 8 , 4 , 10};
    bubbleSort(arr , n);
    for(int i=0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}