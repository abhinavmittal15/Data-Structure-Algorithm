// Link : https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0

#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node *insertAtEnd(Node *head, int x) {
        if(head == NULL) {
            return new Node(x);
        }
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(x);
        return head;
    }
};

int main() {
    Solution obj;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int x = 6;

    Node* newHead = obj.insertAtEnd(head, x);
    while(newHead != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}