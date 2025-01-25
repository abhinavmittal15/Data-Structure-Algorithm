class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        Node* curr = head;
        int count = 1;
        while(curr != nullptr) {
            if(count == x) {
                break;
            }
            curr = curr->next;
            count++;
        }
        if(curr == nullptr) {
            return head;
        }
        if(curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }
        else {
            head = curr->next;
        }
        if(curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        delete curr;
        return head;
    }
};