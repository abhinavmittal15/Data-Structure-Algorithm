#include <iostream>
using namespace std;

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};


class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  Solution solution;
  ListNode* middle = solution.middleNode(head);
  std::cout << middle->val << std::endl;

  return 0;
}