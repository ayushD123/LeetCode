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
        unordered_map<ListNode*,int> mp;
        ListNode* currA=headA;
        while(currA!=NULL){
            mp[currA]=1;
            currA=currA->next;
        }
        currA=headB;
         while(currA!=NULL){
             if(mp[currA]){
                 return currA;
             }
           currA=currA->next;
        }
        return NULL;
    }
};