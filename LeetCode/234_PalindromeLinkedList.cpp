#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>

using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
    public:
    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL) return true;

        ListNode* reversedList = NULL;
        ListNode* current = head;
        while(current != NULL){
            ListNode* newNode = new ListNode(current->val);
            newNode->next = reversedList;
            reversedList = newNode;
            current = current->next;
        }


        ListNode* original = head;
        current = reversedList;
        while(original != NULL && current != NULL){
            if(original->val != current->val){
                return false;
            }
            original = original->next;
            current = current->next;
        }

        if(original == NULL && current == NULL){
            return true;
        }

        return false;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    cout << s.isPalindrome(head) << endl;

    return 0;
}