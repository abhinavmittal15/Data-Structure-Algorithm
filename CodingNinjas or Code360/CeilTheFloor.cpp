//Link : https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    int s = 0;
    int e = n-1;
    int floor = -1;
	int ceiling = -1; 
    while(s <= e){
        int m = s + (e - s)/2;
        if(arr[m] <= x){
            floor = arr[m];
            s = m + 1;
        }
        else{
            e = m - 1;
        }
    }

    s = 0;
    e = n-1;
    while(s <= e){
        int m = s + (e - s)/2;
        if(arr[m] >= x){
            ceiling = arr[m];
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
	return {floor, ceiling};
}


int main(){
    int n = 6;
    int x = 8;
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    pair<int, int> p = getFloorAndCeil(arr, n, x);
    cout << p.first << " " << p.second << endl;
    return 0;
}