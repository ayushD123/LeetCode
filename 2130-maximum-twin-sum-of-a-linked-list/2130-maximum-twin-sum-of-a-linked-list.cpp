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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* cur=head;
        while(cur!=NULL){
            st.push(cur->val);
            cur=cur->next;
        }
        cur=head;
        int ans=0;
        while(!st.empty()){
            ans=max(ans,st.top()+cur->val);
            st.pop();
            cur=cur->next;
        }
        return ans;
    }
};