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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> mp;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;
        
        int sum = 0;
        /*
        mp {0, 1} {1, 1} {3, 2} {0, -3} 
             _      _       _      _
        */
        
        while(dummy){
            
            sum += dummy->val;
            if(mp.count(sum)>0){
                ListNode* prev = mp[sum]->next;
                
                int prev_sum = sum; 
                while(prev != dummy){
                    prev_sum += prev->val;
                    mp.erase(prev_sum);
                    prev = prev->next;
                }       
                mp[sum]->next = dummy->next; 
                
            } else {
                mp[sum] = dummy;
            }
            dummy = dummy->next;
        }
        
        return temp->next;
    }
};