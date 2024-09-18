// Link : https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1

#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    Solution obj;
    int n = 4;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int key = 3;

    cout << obj.searchKey(n, head, key) << endl;
    return 0;
}