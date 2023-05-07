/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA=headA;
        ListNode* currB=headB;
        int na=0;
        int nb=0;
        while(currA!=NULL){
            na++;
            currA=currA->next;
        }
         while(currB!=NULL){
            nb++;
            currB=currB->next;
        }
        ListNode* lar=na>nb?headA:headB;
        ListNode* shor=(lar==headA)?headB:headA;
        int c=abs(na-nb);
        for(int i=0;i<c;++i){
            lar=lar->next;
        }
        while(shor!=lar){
            lar=lar->next;
            shor=shor->next;
        }
        return shor;
    }
};
