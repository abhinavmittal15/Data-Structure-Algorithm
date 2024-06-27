// Link : https://www.codechef.com/START140D/problems/YOGACLASS

#include <bits/stdc++.h>
using namespace std;

int earnMoney(int n, int x, int y){
    int maxEarning = 0;
    // For every possible number of Type 2 sessions from 0 to n/2
    for(int type2Sessions = 0; type2Sessions <= n/2; ++type2Sessions){
        int hoursForType2 = 2 * type2Sessions; // Hours spent in Type 2 sessions
        int hoursForType1 = n - hoursForType2; // Remaining hours for Type 1 sessions
        // Calculate total earning for this combination of Type 1 and Type 2 sessions
        int currentEarning = (type2Sessions * y) + (hoursForType1 * x);
        // Update maxEarning if currentEarning is greater
        maxEarning = max(maxEarning, currentEarning);
    }
    return maxEarning;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int ans = earnMoney(n, x, y);
        cout << ans << endl;
    }
}
