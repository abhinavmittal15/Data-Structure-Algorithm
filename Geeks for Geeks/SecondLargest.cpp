//Link : https://www.geeksforgeeks.org/problems/second-largest3735/1

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    if(n < 2) return -1;
	    
	    set<int> set(arr, arr+n);   //a set sorts the elements in ascending order
	    
	    if(set.size() < 2) return -1;
	    
	    vector<int> sortedArr(set.begin(), set.end());
	    return sortedArr[sortedArr.size()-2];
	}
};

int main(){
    Solution s;
    int arr[] = {4, 6, 3, 5, 7};
    int n = 5;
    cout << s.print2largest(arr, n) << endl;
    return 0;
}