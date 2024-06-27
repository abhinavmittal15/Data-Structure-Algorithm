#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findCenter(vector<vector<int>> &edges){
        // Extract node values from the first edge
        int firstNodeOfFirstEdge = edges[0][0];
        int secondNodeOfFirstEdge = edges[0][1];

        // Extract node values from the second edge
        int firstNodeOfSecondEdge = edges[1][0];
        int secondNodeOfSecondEdge = edges[1][1];

        if (firstNodeOfFirstEdge == firstNodeOfSecondEdge || firstNodeOfFirstEdge == secondNodeOfSecondEdge)
            return firstNodeOfFirstEdge; // The first node of the first edge is the center
        else
            return secondNodeOfFirstEdge; // The second node of the first edge is the center
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << s.findCenter(edges) << endl;
    return 0;
}