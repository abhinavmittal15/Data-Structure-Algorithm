#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val = 0, ListNode* next = nullptr){
        this->val = val;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        if (getCarry(head) == 1)
            return new ListNode(1, head);
        return head;
    }

private:
    int getCarry(ListNode *node)
    {
        int val = node->val * 2;
        if (node->next != nullptr)
            val += getCarry(node->next);

        node->val = val % 10;
        return val / 10;
    }
};

void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next)
            cout<<"->";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);
    
    printList(s.doubleIt(head));
    return 0;
}