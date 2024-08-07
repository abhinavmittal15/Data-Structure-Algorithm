#include<iostream>
#include<unordered_map>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy; 
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumMap; 
        while (current) {
            prefixSum += current->val;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                current = prefixSumMap[prefixSum]->next;
                int tempSum = prefixSum + current->val;
                while (tempSum != prefixSum) {
                    prefixSumMap.erase(tempSum); 
                    current = current->next; 
                    tempSum += current->val; 
                }
                prefixSumMap[prefixSum]->next = current->next;
            } else {
                prefixSumMap[prefixSum] = current;
            }
            current = current->next;
        }
        return dummy->next;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(-3);
    ListNode *node4 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    ListNode* result = s.removeZeroSumSublists(head);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}