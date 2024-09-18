// Link : https://www.naukri.com/code360/problems/search-in-a-linked-list_975381

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, Node<T>* next) {
        this->data = data;
        this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* temp = head;
    while(temp != NULL) {
        if(temp->data == k) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node<int>* head = new Node(3);
    head->next = new Node(6);
    head->next->next = new Node(2);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(-1);
    head->next->next->next->next->next->next = NULL;

    int k = 2;
    cout << searchInLinkedList(head, k) << endl;
    return 0;
}