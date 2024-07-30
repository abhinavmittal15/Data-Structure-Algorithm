// Link : https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

#include<iostream>
#include<cmath>
using namespace std;

class Solution{
public:
	int NthRoot(int n, int m){
	    if(m == 0) return 0;
	    
	    int s = 1;
	    int e = m;
	    while(s <= e){
	        int mid = s + (e-s)/2;
	        if(pow(mid, n) == m){
	            return mid;
	        }
	        else if(pow(mid, n) > m){
	            e = mid - 1;
	        }
	        else{
	            s = mid + 1;
	        }
	    }
	    return -1;
	}  
};

int main(){
    Solution s;
    int n = 2;
    int m = 9;
    cout << s.NthRoot(n, m) << endl;
    return 0;
}