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
    
    /*
    
    1-> 2-> 3-> 4-> 5-> X
    left = 2
    go to left-1
    and ask for the reverse of first right-left+1 nodes  
    1-> 
    4-> 3-> 2-> 5-> X
    
    // sub-routine
    
    1->2->3->4
    1<-2<-3
    
    2->1->3->4
    
    
    */
    
    
    /*
    prev          cur          nxt
    1       ->    2     ->     3
    
                prev           cur   
    1       <-    2            3
    
    */
    
    ListNode* rev_k_first_nodes(ListNode* head, int k){
        
        if(!head->next)return head;
        
        ListNode* start = head;
        ListNode* prev = head, *cur = head->next, *nxt;
        
        while(--k){
            nxt = cur->next;
            
            cur->next = prev;
        
            prev = cur; 
            cur = nxt;    
        }
        
        start->next = cur;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int cnt = right-left+1; // 3
        ListNode *rev = nullptr;
        ListNode* dummy = new ListNode();
        
        dummy->next = head;
        
        ListNode* itr = dummy;
        for(int i=0; i<left-1; ++i){
            itr=itr->next;
        }

        rev = rev_k_first_nodes(itr->next, cnt);
        itr->next = rev;
        return dummy->next; 
        
        // return rev_k_first_nodes(head, 4);
    }
};