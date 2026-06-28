/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;
        int skipA = 0, skipB = 0;
        while(listA != listB) {
            if(listA) {
                listA = listA->next;
            } else {
                listA = headB;
            }
            if(listB) {
                listB = listB->next;
            } else {
                listB = headA;
            }
        }
        return listA;
    }
};