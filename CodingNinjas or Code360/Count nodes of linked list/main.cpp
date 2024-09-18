// Link : https://www.naukri.com/code360/problems/count-nodes-of-linked-list_5884

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

int length(Node *head)
{
    Node* temp = head;
    int count = 0;
	while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next = NULL;
    
    cout << length(head) << endl;
    return 0;
}