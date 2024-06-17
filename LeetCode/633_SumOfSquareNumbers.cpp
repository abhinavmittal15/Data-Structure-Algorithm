#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0; i*i<=c; i++){
            double j = sqrt(c - i*i);
            if(j == int(j)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    int c = 5;
    cout << s.judgeSquareSum(c) << endl;
    return 0;
}