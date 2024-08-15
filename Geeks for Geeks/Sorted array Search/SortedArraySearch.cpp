// Link : https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

#include<iostream>
using namespace std;

class Solution{
public: 
    int searchInSorted(int arr[], int N, int K) 
    { 
    
        for(int i=0; i<N; i++){
            if(arr[i] == K){
                return 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    int N = 5;
    int K = 6;
    int arr[N] = {1, 2, 3, 4, 6};
    cout << s.searchInSorted(arr, N, K) << endl;
    return 0;
}