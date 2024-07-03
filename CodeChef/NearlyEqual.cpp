// Link : https://www.codechef.com/START141D/problems/SAMESAME

#include <bits/stdc++.h>
using namespace std;

int nearlyEqual(string& a, string& b) {
    int n = a.length();
    int m = b.length();
    int minHammingDist = INT_MAX;

    for(int i = 0; i <= n - m; i++) {
        int count = 0;
        for(int j = 0; j < m; j++) {
            if(a[i + j] != b[j]) {
                count++;
            }
        }
        minHammingDist = min(minHammingDist, count);
    }
    return minHammingDist;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    string a, b;
        cin >> a >> b;
	    cout << nearlyEqual(a, b) << endl;
	}
	return 0;
}
