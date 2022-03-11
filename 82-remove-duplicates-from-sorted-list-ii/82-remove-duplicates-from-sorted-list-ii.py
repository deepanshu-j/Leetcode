# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rem(self, head: Optional[ListNode], delete_this:Optional[bool]):
        if head.next!=None:
            if head.next.val==head.val:
                delete_this=True
            head.next=self.rem(head.next, head.next.val==head.val)
        if delete_this:
            return head.next
        return head
        
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode(-1000)
        dummy.next=head
        
        dummy=self.rem(dummy, False)
        return dummy.next