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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *f=nullptr, *s=nullptr;
        ListNode *first_head = nullptr, *second_head = nullptr;
        
        while(head){
        
            ListNode* next_head = head->next;
            if(head->val < x){
                
                // put in f
                
                if(f==nullptr){
                    f = head; 
                    first_head = f;
                }else{
                    f->next = head;    
                    f = f->next;                    
                }
                if(f && f->next)f->next = nullptr;
            }else{
                
                // put in s
                
                if(!s){
                    second_head = head;
                    s = head;
                }else{
                    s->next = head;
                    s = head;    
                }
                if(s && s->next)s->next = nullptr;
            }
            
            head = next_head;
            
        }
        
        if(!first_head)return second_head;
            
        f->next = second_head;
        return first_head;
        
    }
};