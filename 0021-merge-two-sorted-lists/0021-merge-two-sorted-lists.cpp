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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2==NULL){
            return list1;
        }
         if(list1==NULL){
            return list2;
        }
        ListNode* ans=new ListNode(0);
        ListNode* tmp=ans;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                ListNode* k=new ListNode(list1->val);
                tmp->next=k;
                tmp=k;
                list1=list1->next;
            }else{
                ListNode* k=new ListNode(list2->val);
                tmp->next=k;
                tmp=k;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
            ListNode* k=new ListNode(list1->val);
                tmp->next=k;
                tmp=k;
                list1=list1->next;
        }
        while(list2!=NULL){
            ListNode* k=new ListNode(list2->val);
                tmp->next=k;
                tmp=k;
                list2=list2->next;
        }
        return ans->next;
    }
};