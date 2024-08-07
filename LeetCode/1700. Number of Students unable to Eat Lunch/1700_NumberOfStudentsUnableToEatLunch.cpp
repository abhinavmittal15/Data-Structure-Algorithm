#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {};
        for (int s : students)
            count[s]++;
        int i = 0;
        for (; i < sandwiches.size() && count[sandwiches[i]]; i++)
            count[sandwiches[i]]--;
        return sandwiches.size() - i;
    }
};

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    Solution S;
    int result = S.countStudents(students, sandwiches);

    cout << result << endl;

    return 0;
}