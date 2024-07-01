// Link : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> arr11;
        vector<int> arr22;
        copy(arr1, arr1 + n, back_inserter(arr11));
        copy(arr2, arr2 + m, back_inserter(arr22));
        // copy(int_array, int_array + sizeof(int_array) / sizeof(int), std::back_inserter(arr));
        
        for(int i=0; i<m; i++){
            arr11.push_back(arr22[i]);
        }
        set<int> vectorToSet(arr11.begin(), arr11.end());
        vector<int> setToVector(vectorToSet.begin(), vectorToSet.end());
        return setToVector;
    }
};

int main(){
    Solution s;
    int arr1[] = {1, 2, 2, 4};
    int arr2[] = {2, 4, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    vector<int> result = s.findUnion(arr1, arr2, n, m);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}