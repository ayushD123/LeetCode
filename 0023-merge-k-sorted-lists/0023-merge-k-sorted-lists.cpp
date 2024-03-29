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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val>l2->val){
                ListNode* t=new ListNode(l2->val);
                curr->next=t;
                curr=curr->next;
                l2=l2->next;
            }else{
                ListNode* t=new ListNode(l1->val);
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){return NULL;}
        while(lists.size()>1){
            lists.push_back(merge(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};