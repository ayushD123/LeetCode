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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            int v=l1->val+l2->val+carry;
           
               ListNode* tmp=new ListNode(v%10);
                carry=v/10;
                 curr->next=tmp;
                curr=tmp;
         
               

            
           l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int v=l1->val+carry;
           
               ListNode* tmp=new ListNode(v%10);
                carry=v/10;
                 curr->next=tmp;
                curr=tmp;
         
               

            
           l1=l1->next;
        }
         while(l2!=NULL){
            int v=l2->val+carry;
           
               ListNode* tmp=new ListNode(v%10);
                carry=v/10;
                 curr->next=tmp;
                curr=tmp;
         
               

            
           l2=l2->next;
        }
        if(carry!=0)
      curr->next=new ListNode(carry);
        return ans->next;
    }
};