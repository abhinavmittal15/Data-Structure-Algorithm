// The link to the problem:- https://www.codingninjas.com/studio/problems/cooking-ninjas_1164174

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &rank, int m, int mid){
    int time = 0;
    int cook = 0;
    for (int i = 0; i < rank.size(); i++) {
        time = rank[i];
        int j = 2;
        while (time <= mid) {
            cook++;
            time += rank[i] * j;
            j++;
        }
        if (cook >= m){
            return true;
        }
    }
}

int minCookTime(vector<int> &rank, int m) {
    int s = 0;  
    int e = 1e8;
    int ans = 0;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(rank, m, mid)) {
            ans = mid;
            e = mid - 1;
        } 
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> testCases = {
        {1, 1, 10},
        {4, 11, 1, 2, 3, 4}
    };

    for(auto &test : testCases){
        int n = test[0];
        int m = test[1];
        vector<int> rank(test.begin() + 2, test.end());
        cout << minCookTime(rank, m) << endl;
    }
    return 0;
}