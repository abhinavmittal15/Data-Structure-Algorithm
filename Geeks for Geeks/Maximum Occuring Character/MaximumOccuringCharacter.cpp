//The link to the problem: https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char getMaxOccuringChar(string str) {
        vector<int> count(256, 0);
        char result = 'z';
        int max = -1;

        for(int i=0; i<str.length(); i++){
            count[str[i]]++;
            if(count[str[i]] > max || (count[str[i]] == max && str[i] < result)){
                max = count[str[i]];
                result = str[i];
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    string str = "testsample";
    cout << s.getMaxOccuringChar(str) << endl;
    return 0;
}
