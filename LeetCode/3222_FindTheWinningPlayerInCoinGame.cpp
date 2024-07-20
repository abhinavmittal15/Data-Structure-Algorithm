#include<iostream>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        int totalWays = min(x, y/4);
        if(totalWays % 2 == 1){
            return "Alice";
        }
        else{
            return "Bob";
        }
    }
};

int main(){
    Solution s;
    int x = 2;
    int y = 7;
    cout << s.losingPlayer(x, y) << endl;
    return 0;
}