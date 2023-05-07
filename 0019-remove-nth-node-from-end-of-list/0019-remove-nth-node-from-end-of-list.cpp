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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        if(!head) return head;
        ListNode* curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        if(cnt==1){
            return NULL;
        }
        if(n==cnt){
            head=head->next;
            return head;
        }
       int c=cnt-n-1;
        curr=head;
      
        while(curr!=NULL && c>0){
            curr=curr->next;
            c--;
        }
        curr->next=curr->next->next;
        return head;
    }
};