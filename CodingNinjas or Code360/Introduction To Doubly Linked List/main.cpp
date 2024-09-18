//Link : https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next; Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node* next, Node* prev) : data(x), next(next), prev(prev) {}
};

Node* constructDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main() {
    vector<int> arr = {4, 2, 5, 1};
    Node* head = constructDLL(arr);

    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}