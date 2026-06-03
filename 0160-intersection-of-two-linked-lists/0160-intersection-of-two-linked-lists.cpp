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
        // Boundary check
        if (headA == NULL || headB == NULL) return NULL;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Loop continues until the two pointers meet
        while (ptrA != ptrB) {
            // Move ptrA to headB if it reaches the end, otherwise move to next node
            ptrA = (ptrA == NULL) ? headB : ptrA->next;
            
            // Move ptrB to headA if it reaches the end, otherwise move to next node
            ptrB = (ptrB == NULL) ? headA : ptrB->next;
        }

        // Either they met at the intersection node, or both are NULL (no intersection)
        return ptrA;
    }
};