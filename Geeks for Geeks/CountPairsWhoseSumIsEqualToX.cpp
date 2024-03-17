//The link to the problem:- https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class Solution{
    public:
    int countPairs(struct Node* head1, struct Node* head2, int x){
        unordered_set<int> s;
        while(head1 != NULL){
            s.insert(head1 -> data);
            head1 = head1 -> next;
        }
        int count = 0;
        while(head2 != NULL){
            if(s.find(x - head2 -> data) != s.end()){
                count++;
            }
            head2 = head2 -> next;
        }
        return count;
    }
};