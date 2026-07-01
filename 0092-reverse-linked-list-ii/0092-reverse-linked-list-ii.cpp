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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* beforeLeft = dummy;

        int i = 1;
        while (i < left) {
            beforeLeft = beforeLeft->next;
            i++;
        }

        ListNode* leftNode = beforeLeft->next;
        i = 0;
        ListNode* rightNode = leftNode;
        while (i < (right - left)) {
            rightNode = rightNode->next;
            i++;
        }

        ListNode* afterRight = rightNode->next;
        ListNode* prev = afterRight;
        ListNode* curr = leftNode;

        while (curr != afterRight) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        beforeLeft->next = rightNode;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};