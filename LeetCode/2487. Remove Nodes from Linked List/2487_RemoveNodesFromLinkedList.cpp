/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        // Reverse the list
        head = reverseList(head);
        
        // Initialize maxNode to head
        ListNode* maxNode = head;
        
        // Initialize current to head
        ListNode* current = head;
        
        // This line starts a loop that continues as long as current is not NULL and current has a next node. This is to prevent accessing NULL pointers in the loop.
        while(current && current->next) {
            // If the next node's value is less than maxNode's value, delete it
            if(current->next->val < maxNode->val) {
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp;
            } 
            else {
                // Otherwise, move to the next node and update maxNode
                current = current->next;
                maxNode = current;
            }
        }
        
        // Reverse the list again to restore the original order
        head = reverseList(head);
        
        return head;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        return prev;
    }
};

void printLinkedList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);    
    printLinkedList(s.removeNodes(head));
    return 0;
}