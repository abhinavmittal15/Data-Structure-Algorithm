// The link to the problem:- https://www.codingninjas.com/studio/problems/painter's-partition-problem_1089557

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& boards, int n, int k, int mid){
    if(k>n){
        return false;
    }
    
    int painterCount = 1;
    int larMinDis =0;
    
    for(int i=0; i<n; i++){
        if(larMinDis + boards[i] <= mid){
            larMinDis += boards[i];
        }
        else{
            painterCount++;
            if(painterCount > k || boards[i] > mid){
                return false;
            }
            larMinDis = boards[i];
        }
        if(painterCount > k){
            return false;
        }

    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s= 0;
    int sum = 0;
    int n = boards.size();
    for(int i=0; i<n; i++){
        sum = sum + boards[i];
    }
    int e = sum;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(boards, n, k, mid)){
            ans = mid;
            e= mid-1;
        }
        else{
            s= mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;
    cout << findLargestMinDistance(boards, k) << endl;
    return 0;
}