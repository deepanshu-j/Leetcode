# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def list_len(self,l1):
        if l1==None:
            return 0
        return 1+self.list_len(l1.next)
    
    def make_list(self,sz):
        dummy = ListNode(0)
        res = dummy
        
        while sz:
            dummy.next = ListNode(0)
            dummy = dummy.next
            sz-=1
            
        return res.next
    
    
    def placeinfrontof(self,l1, infront):
        assert infront!=None
        res = infront
        while infront.next!=None:
            infront=infront.next
        
        infront.next=l1
        return res
    
    def recc(self,l1, l2):
        
        # base case #
        if l1.next==None:
            assert l2.next==None
            val=0
            if l1!=None:
                val=val+l1.val
            if l2!=None:
                val=val+l2.val
            new_list = ListNode(val%10)
            return (new_list, val//10)
        
        # recc #
        val=0
        if l1!=None:
            val=val+l1.val
        if l2!=None:
            val=val+l2.val
        
        prev_list, carry = self.recc(l1.next, l2.next)
        
        val = val+carry
        
        new_list = ListNode(val%10)
        new_list.next = prev_list
        return (new_list, val//10)
        
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        len1 = self.list_len(l1)
        len2 = self.list_len(l2)
        
        # append zeros 
     
        infront = self.make_list(abs(len1-len2))
        
        if len1<len2:
            l1=self.placeinfrontof(l1, infront)
        elif len2<len1:
            l2=self.placeinfrontof(l2, infront)
        
        my_list, carry = self.recc(l1, l2)

        if carry!=0:
            infront = ListNode(carry)
            my_list = self.placeinfrontof(my_list, infront)
        return my_list
        
        