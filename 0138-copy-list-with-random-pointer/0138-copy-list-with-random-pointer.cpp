/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* curr = head;
        while(curr) {
           Node* next = curr->next;
           Node* clone = new Node(curr->val);
           curr->next = clone;
           clone->next = next;
           curr = next; 
        }
        curr = head;
        while(curr) {
            if(curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* temp = head->next;
        Node* cloneHead = temp;
        while(curr) {
            curr->next = curr->next->next;
            if(temp->next) {
                temp->next = temp->next->next;
            }
            curr = curr->next;
            temp = temp->next;
        }
        return cloneHead;
    }
};