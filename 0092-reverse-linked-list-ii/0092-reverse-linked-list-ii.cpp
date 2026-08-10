class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* before = dummy;

        // Move to node just before left
        for(int i = 1; i < left; i++) {
            before = before->next;
        }

        ListNode* curr = before->next;
        ListNode* prev = NULL;

        // Reverse left to right
        for(int i = 0; i < right - left + 1; i++) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Connect left part to reversed part
        before->next->next = curr;
        before->next = prev;

        return dummy->next;
    }
};