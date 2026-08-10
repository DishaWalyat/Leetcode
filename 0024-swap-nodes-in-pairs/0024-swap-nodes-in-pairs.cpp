class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL && curr->next != NULL) {

            ListNode* next1 = curr->next;
            ListNode* next2 = curr->next->next;

            // curr = first
            // next1 = second
            // next2 = node after the pair

            curr->next = next2;
            next1->next = curr;

            if(prev != NULL)
                prev->next = next1;
            else
                head = next1;

            prev = curr;
            curr = next2;
        }

        return head;
    }
};