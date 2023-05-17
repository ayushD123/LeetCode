# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        a = []
        while head:
            a.append(head.val)
            head = head.next
        i, j = 0, len(a) - 1
        mx = 0
        while i < j:
            mx = max(mx, a[i] + a[j])
            i += 1
            j -= 1
        return mx
        