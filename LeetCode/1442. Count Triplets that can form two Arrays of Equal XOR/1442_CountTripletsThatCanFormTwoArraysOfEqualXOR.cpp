#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr){
        int n = arr.siz();
        vector<int> prefixXOR(n + 1);

        for(int i=0; i<n; i++)
            prefixXOR[i+1] = prefix[i] ^ arr[i];

        int count = 0;
        for(int i=0; i< n-1; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j; k<n; k++){
                    if(prefixXOR[i] == prefixXOR[k+1])
                        count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2,3,1,6,7};
    cout << sol.countTriplets(arr) << endl;
    return 0;
}