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
        
        ListNode* res=new ListNode();
        ListNode* head=res;
        int carry=0;
        while(l1 or l2){
            int ans=
                (l1?l1->val:0)+
                (l2?l2->val:0)+
                carry;
            int val=ans%10;
            carry=ans/10;
            
            head->next = new ListNode(val);
            head=head->next;
            
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        
        if(carry){
            head->next = new ListNode(carry);
        }
        
        return res->next;
    }
};