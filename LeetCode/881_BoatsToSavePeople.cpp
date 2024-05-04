#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int boat = 0;
        int left = 0;
        int right = people.size() - 1;
        while(left <= right){
            int remain = limit - people[right];
            right--;
            boat++;
            if(left <= right && remain >= people[left] )
                left++;
        }
        return boat;
    }
};

int main(){
    Solution s;
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;
    return 0;
}