#include<iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int round = time / (n-1);
        time = time % (n-1);
        int ans = 0;
        if(round % 2 == 0){ // if even start from left side
            ans = 1 + time;
        }
        else{               //if odd start from the right side
            ans = n - time;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n = 4;
    int time = 5;
    cout << s.passThePillow(n, time) << endl;
    return 0;
}