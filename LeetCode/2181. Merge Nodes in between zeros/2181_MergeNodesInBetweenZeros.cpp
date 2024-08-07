#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        // Dummy node preceding the result linked list
        ListNode *dummy = new ListNode();

        // Tail keeps track of the last node of the result list
        ListNode *tail = dummy;

        // Variable to accumulate values of nodes until a zero node encountered
        int sum = 0;

        // Iterate over nodes starting after the first (dummy) one
        for (ListNode *current = head->next; current != nullptr; current = current->next)
        {
            // If current value is not zero, add to sum
            if (current->val != 0)
            {
                sum += current->val;
            }
            else
            {
                // If a zero node is reached, add a new node with the accumulated sum to the result list
                tail->next = new ListNode(sum);
                tail = tail->next; // Move the tail forward
                sum = 0;           // Reset sum for next segment
            }
        }
        // Return the head of the resulting list
        return dummy->next;
    }
};

int main()
{
    ListNode *head = 0;
}