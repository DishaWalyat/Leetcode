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
    ListNode* oddEvenList(ListNode* head) {
        //basecondi
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* even = q;
        while (q != NULL && q->next != NULL) {
            if (p != NULL) {
                p->next = q->next;
                p = p->next;
            }

            if (q != NULL) {
                q->next = p->next;
                q = q->next;
            }
        }
        p->next = even;//endmein hum odd and even chaines ko attach kar denge 
        return head;
    }
};