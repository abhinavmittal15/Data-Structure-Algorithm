#include <iostream>
#include <unordered_set>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(slow != fast) {
            if(fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};

int main(){
    ListNode *head = new ListNode(3);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(0);
    ListNode *node3 = new ListNode(-4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    Solution s;
    cout << s.hasCycle(head) << endl;
    return 0;
}