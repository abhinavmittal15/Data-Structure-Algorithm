//Link : https://www.naukri.com/code360/problems/introduction-to-linked-list_8144737

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main() {
    vector<int> arr = {4, 2, 5, 1};
    Node* head = constructLL(arr);
    Node* current = head;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}