// Link : https://www.codechef.com/START141D/problems/LUCLO

#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    int ans =  4*1 + 3*(n-1);
    return ans;
}

int main() {
	int n;
	cin >> n;
	cout << solve(n);
    return 0;
}
