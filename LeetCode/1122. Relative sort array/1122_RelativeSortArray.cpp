#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

class Solution{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2){

        unordered_map<int, int> arr1_count;
        //here we count the occurence of each number in arr1
        for(int num : arr1){
            arr1_count[num]++;
        }

        vector<int> res;
        //here we add each number from arr2 to res as many times as it appears in arr1
        for(int num : arr2){
            while(arr1_count[num] --> 0){
                res.push_back(num);
            }
        }

        vector<int> remaining;
        //here we add the remaining numbers those who doesnt appears in arr2 to res in ascending order
        for(auto& pair : arr1_count){
            while(pair.second --> 0){
                remaining.push_back(pair.first);
            }
        }

        sort(remaining.begin(), remaining.end());
        res.insert(res.end(), remaining.begin(),remaining.end());

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> res = sol.relativeSortArray(arr1, arr2);
    for(int num : res){
        cout << num <<" ";
    }
    cout << endl;
    return 0;
}