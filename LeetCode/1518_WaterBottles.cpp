#include<iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles >= numExchange){
            int remaining = numBottles % numExchange;
            numBottles = numBottles / numExchange;
            ans += numBottles;    
            numBottles += remaining;
        }
        return ans;
    }
};

//OR WE CAN USE 

/*
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1)/(numExchange - 1);
    }
*/

int main(){
    Solution s;
    int numBottles = 9;
    int numExchange = 3;
    cout << s.numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}