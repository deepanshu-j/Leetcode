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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* storeNext = head->next;
            head->next = prev;
            prev = head;
            head = storeNext;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMid(head);
        mid = reverseList(mid);
        while(head and mid){
            if(head->val != mid->val) return 0;
            head = head->next, mid = mid->next;
        }
        return 1;
    }
};