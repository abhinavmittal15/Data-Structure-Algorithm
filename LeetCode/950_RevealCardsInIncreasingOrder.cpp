#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
// #include<ranges>
using namespace std;

class Solution{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)    {
        sort(deck.begin(), deck.end(), greater<int>());

        deque<int> dq{deck[0]};

        for (int i = 1; i < deck.size(); ++i)  {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        return {dq.begin(), dq.end()};
    }
};

int main(){
    Solution obj;
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> res = obj.deckRevealedIncreasing(deck);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}