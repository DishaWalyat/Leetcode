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
    ListNode* rotateRight(ListNode* head, int k) {

        //  Edge cases
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Step 1: Find length and tail
        ListNode* temp = head;
        int length = 1;

        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }

        // Step 2: Normalize k
        k = k % length;
        if (k == 0) return head;

        int n = length - k;

        // Step 3: Make circular
        temp->next = head;

        // Step 4: Find new tail
        ListNode* mover = head;
        for (int i = 1; i < n; i++) {
            mover = mover->next;
        }

        // Step 5: Break circle
        ListNode* newHead = mover->next;
        mover->next = NULL;

        return newHead;
    }
};
