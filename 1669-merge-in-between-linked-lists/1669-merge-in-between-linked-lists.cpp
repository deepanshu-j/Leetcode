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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aminus1 = list1;
        while(--a) aminus1 = aminus1->next;
        ListNode* bthNode = list1;
        ++b;
        while(b--) bthNode = bthNode->next;
        
        aminus1->next = list2;
        while(list2->next) list2 = list2->next;
        list2->next = bthNode;
        
        return list1;
    }
};