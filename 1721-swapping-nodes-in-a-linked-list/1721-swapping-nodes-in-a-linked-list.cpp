/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr=head;
        int n=0;
        while(curr!=NULL){
            curr=curr->next;
            n++;
        }
        int x,y;
        curr=head;
        int m=1;
        while(curr!=NULL){
            if(m==k){
                x=curr->val;
            }
            if(m==(n-k+1)){
               y=curr->val;
                curr->val=x;
            } 
            curr=curr->next;
            m++;
        }
       // cout<<x<<" "<<y;
        curr=head;
        m=1;
        while(curr!=NULL){
            if(m==k){
                curr->val=y;
                
            }
             if(m==(n-k+1)){
                curr->val=x;
                
            }
            curr=curr->next;
            m++;
        }
        return head;
        
    }
};