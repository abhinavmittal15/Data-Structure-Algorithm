//Link : https://practice.geeksforgeeks.org/contest/job-a-thon-35-hiring-challenge/problems

#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int FindBits(int n, int x) {
        int setBits = countSetBits(x);
        return pow(2, n - setBits);
    }
    
private:
    int countSetBits(int x) {
        int count = 0;
        while (x) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
};

int main(){
    int n, x;
    // cin >> n >> x;
    n = 4;
    x = 3;
    Solution obj;
    cout << obj.FindBits(n, x) << endl;
    return 0;
}