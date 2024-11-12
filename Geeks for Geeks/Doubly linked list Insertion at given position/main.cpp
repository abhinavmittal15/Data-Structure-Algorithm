#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

class Solution {
public:
    Node *addNode(Node* head, int pos, int data) {
        Node *curr = head;
        int count = 0;
        while (curr != nullptr) {
            if (count == pos) {
                break;
            }
            curr = curr->next;
            count++;
        }
        if (curr == nullptr) {
            return head;
        }
        Node* newNode = new Node(data);
        newNode->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
        return head;
    }
};

Node *insert(Node *head, int x) {
    if (head == NULL) {
        return new Node(x);
    }
    Node *n = new Node(x);
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    return head;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(2);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.addNode(head, 2, 6);

    cout << "List after adding node: ";
    printList(head);

    return 0;
}