#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(colors[i] != colors[(i+1) % n] && colors[(i+1) % n] != colors[(i+2) % n] ){
                count++;
            }
        }
        return count++;
    }
};

int main(){
    Solution s;
    vector<int> colors = {0, 1, 0, 0, 1};
    cout << s.numberOfAlternatingGroups(colors) << endl;
    return 0;
}