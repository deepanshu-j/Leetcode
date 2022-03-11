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
    
    int list_len(ListNode* head){
        if(!head)return 0;
        return 1+list_len(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int l=list_len(head);
    
        k=k%l;
        
        if(k==0)return head;
        ListNode* new_head;
        ListNode* tail;
        
        int iterations=l-k-1;
        
        ListNode* dummy=head;
        while(iterations--)
            dummy=dummy->next;
        
        new_head=dummy->next;
        dummy->next=nullptr;
        
        dummy=new_head;
        while(dummy && dummy->next){
            dummy=dummy->next;
        }
        if(dummy)
        dummy->next=head;
        
        return new_head;
        
        
    }
};