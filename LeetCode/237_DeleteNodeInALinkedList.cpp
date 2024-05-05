#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

int main() {
    Solution sol;

    //Creating the list
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    //Find the desired Node in the list
    int x = 5; //nodeToDelete
    ListNode* node = head;
    while(node!= NULL && node->val!= x){
        node = node->next;
    }

    //Delete the node
    if(node!=NULL)
        sol.deleteNode(node);

    //Print the list
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}