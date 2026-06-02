class Solution {
public:

    // merge 2 sorted lists
    ListNode* merge(ListNode* left, ListNode* right){

        ListNode dummy(0);

        ListNode* tail = &dummy;

        while(left != NULL && right != NULL){

            if(left->val < right->val){

                tail->next = left;
                left = left->next;
            }
            else{

                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if(left != NULL){
            tail->next = left;
        }

        if(right != NULL){
            tail->next = right;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        // base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        // find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        // split list
        ListNode* mid = slow->next;

        slow->next = NULL;

        // recursive sort
        ListNode* left = sortList(head);

        ListNode* right = sortList(mid);

        // merge sorted halves
        return merge(left, right);
    }
};