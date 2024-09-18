//Link : https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
public:
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
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = obj.constructLL(arr);
    Node* current = head;
    while(current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}