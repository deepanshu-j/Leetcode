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
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast and fast->next){
            slow  = slow->next, fast = fast->next->next;
        }
        
        return slow;
    }
    
    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        
        ListNode* mid = getMid(head);
        ListNode* temp = head;
        while(temp->next != mid) temp = temp->next;
        temp->next = NULL;
        mid = reverseList(mid);
        ListNode* ans = new ListNode(-1);
        while(head and mid){
            ans->next = head; head = head->next;
            ans = ans->next;
            ans->next = mid; mid = mid->next;
            ans = ans->next;
        }        
    }
    
};