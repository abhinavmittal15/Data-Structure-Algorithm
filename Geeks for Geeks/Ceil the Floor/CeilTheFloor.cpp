//Link : https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
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
};

int main(){
    Solution obj;
    int x = 7;
    vector<int> arr = {5, 6, 9, 9, 6, 5, 5, 6};
    vector<int> res = obj.getFloorAndCeil(x, arr);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}