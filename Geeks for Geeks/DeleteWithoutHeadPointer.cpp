// The link to the problem :- https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1

class Solution{
    public:
    void deleteNode(Node *del_node){
        del_node->data = del_node -> next -> data;
        del_node -> next = del_node -> next -> next;
    }
}