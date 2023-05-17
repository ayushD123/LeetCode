//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  Node* merge(Node * l1,Node * l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        Node* ans=new Node(0);
        Node* curr=ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->data>l2->data){
                Node* t=new Node(l2->data);
                curr->next=t;
                curr=curr->next;
                l2=l2->next;
            }else{
                Node * t=new Node(l1->data);
                curr->next=t;
                curr=curr->next;
                l1=l1->next;
            }
            
            
        }
        if(l1!=NULL){
            curr->next=l1;

        }
        if(l2!=NULL){
           curr->next=l2;

        }
        return ans->next;
        
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           vector<Node*> lists;
           for(int i=0;i<K;++i){
               lists.push_back(arr[i]);
           }
            if(lists.size()==0){return NULL;}
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends