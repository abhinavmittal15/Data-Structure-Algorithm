#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skillLevels) {
        sort(skillLevels.begin(), skillLevels.end());
        int n = skillLevels.size();
        int sum = skillLevels[0] + skillLevels[n-1];
        int i = 0;
        int j = n-1;
        long long ans = 0;
        while(i < j) {
            if(skillLevels[i] + skillLevels[j] != sum) {
                return -1;
            }
            ans += skillLevels[i] * skillLevels[j];
            i++;
            j--;
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> skillLevels = {3, 2, 5, 1, 3, 4};
    cout << obj.dividePlayers(skillLevels) << endl;
    return 0;
}