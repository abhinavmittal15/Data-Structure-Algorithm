// The link to the problem:- https://www.codingninjas.com/studio/problems/aggressive-cows_1082559


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 10;
vector<pii> g[N];
ll dp[N], cnt[N];

bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=1; i<=stalls.size()-1; i++){
        if(stalls[i] - lastPos >= mid){
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}



int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s=0;
    int maxi = -1;
    for(int i=0; i<stalls.size(); i++){
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    int n = 3, k = 2;
    vector<int> stalls = {1, 2, 3};
    cout << aggressiveCows(stalls, k) << endl;
    return 0;
}