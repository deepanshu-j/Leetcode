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
    ListNode* reverseList(ListNode* head) {
        
        if(!head->next)return head;
        
        ListNode* new_head=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr; 
        
        return new_head;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head, *slow = head;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        
        ListNode* new_mid = reverseList(slow);
        
        while(head->next){
            
            if(head->val != new_mid->val)return 0;
            head = head->next;
            new_mid = new_mid->next;
        }
        return 1;
    }
};