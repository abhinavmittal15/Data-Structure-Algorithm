//Link : https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
public:
    int getCount(struct Node* head) {
        Node* temp = head;
        int count = 0;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main() {
    Solution obj;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << obj.getCount(head) << endl;
    return 0;
}