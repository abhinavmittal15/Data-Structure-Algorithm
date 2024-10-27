#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int count = 0;
        bool swapped = true;
        while(swapped) {
            swapped = false;
            for(int i=0; i<s.length()-1; i++) {
                if(s[i] == '1' && s[i+1] == '0') {
                    swap(s[i], s[i+1]);
                    count++;
                    swapped = true;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    string s = "11000111";
    cout << obj.minimumSteps(s) << endl;
    return 0;
}