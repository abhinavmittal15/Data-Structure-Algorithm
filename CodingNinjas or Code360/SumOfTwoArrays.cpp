//The link to the problem : https://www.naukri.com/code360/problems/sum-of-two-arrays_893186

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> ans){
    int s=0;
    int e=ans.size()-1;
    while(s<e){
        swap(ans[s++], ans[e--]);
    }
    return ans;
}

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m){
    int i = n-1;
    int j = m-1;
    int carry = 0;
    vector<int> ans;

    while(i>=0 && j>=0){
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;
        
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i>=0){
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

    while(j>=0){
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }

    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    vector<int> ans = findArraySum(a, n, b, m);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

}