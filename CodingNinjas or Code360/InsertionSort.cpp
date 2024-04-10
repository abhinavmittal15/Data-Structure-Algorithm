// Link to problem : https://www.naukri.com/code360/problems/insertion-sort_3155179

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, std::vector<int> &arr){ // Remove "using namespace std;"
    for(int i = 1 ; i < n ; i++){
        int temp = arr[i];
        int j = i -1;
        for( ; j >= 0; j-- ){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(){
    int n = 4;
    std::vector<int> arr = {4, 2, 3, 1};
    insertionSort(n, arr);
    for(int i = 0 ; i < n ; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}