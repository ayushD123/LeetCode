//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *prev=NULL;
        while(first!=NULL){
            Node* nxt=first->next;
            first->next=prev;
            prev=first;
            first=nxt;
        }
        first=prev;
        prev=NULL;
        while(second!=NULL){
            Node* nxt=second->next;
            second->next=prev;
            prev=second;
            second=nxt;
        }
        second=prev;
        Node *ans=new Node(0);
        Node *tmp=ans;
        int carry=0;
        while(first!=NULL && second!=NULL){
            int val=first->data+second->data+carry;
            Node *n=new Node(val%10);
            carry=val/10;
            tmp->next=n;
            tmp=n;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
             int val=first->data+carry;
            Node *n=new Node(val%10);
            carry=val/10;
            tmp->next=n;
            tmp=n;
            first=first->next;
            
        }
         while(second!=NULL){
             int val=second->data+carry;
            Node *n=new Node(val%10);
            carry=val/10;
            tmp->next=n;
            tmp=n;
            second=second->next;
            
        }
        if(carry!=NULL){
            tmp->next=new Node(carry);
        }
        ans=ans->next;
        prev=NULL;
        while(ans!=NULL){
            Node* nxt=ans->next;
            ans->next=prev;
            prev=ans;
            ans=nxt;
        }
        ans=prev;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends