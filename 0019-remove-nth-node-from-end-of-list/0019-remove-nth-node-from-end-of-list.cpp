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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy=new ListNode(0,head);

        ListNode*fast=dummy;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        ListNode*slow=dummy;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;//slow and fast ke bichme hmesha n ka gap rahega 
        }
        slow->next=slow->next->next;//deleting one 
        return dummy->next;//head of new list
    }
};