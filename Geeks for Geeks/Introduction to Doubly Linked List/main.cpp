// Link : https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
public:
    Node* constructDLL(vector<int>& arr) {
        if(arr.empty()) return nullptr;
        
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1; i<arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            temp->prev = prev;
            prev->next = temp;
            prev = temp;
        }
        return head;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = obj.constructDLL(arr);
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}