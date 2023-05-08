/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* nd=new Node(0);
        Node *curr=head;
        Node* tmp=nd;
        while(curr!=NULL){
            Node *n=new Node(curr->val);
            tmp->next=n;
            tmp=n;
            mp[curr]=n;
            curr=curr->next;
        }
        curr=head;
         while(curr!=NULL){
            
           Node *cpy=mp[curr];
            Node* cpyran=mp[curr->random];
             cpy->random=cpyran;
             curr=curr->next;
        }
        return nd->next;
    }
};