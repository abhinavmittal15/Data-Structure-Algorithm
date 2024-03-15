#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

class Solution
{
public:
    void sort(Node **head)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        Node *temp = *head;
        while(temp != NULL){
            pq.push(temp->data);
            temp = temp->next;
        }
        temp = *head;
        while(!pq.empty()){
            temp->data = pq.top();
            pq.pop();
            temp = temp->next;
        }
    }
};

int main()
{
    Solution solution;
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(2);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next = new Node(7);

    solution.sort(&head);

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}