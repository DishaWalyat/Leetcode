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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Vector to store all values from every node
        vector<int> allValues;

        // Loop through each linked list
        for (auto list : lists) {
            // Traverse the current list and store its values
            while (list != NULL) {
                allValues.push_back(list->val);
                list = list->next;
            }
        }

        // Sort all collected values
        sort(allValues.begin(), allValues.end());

        // Create a dummy head for the final result list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        // Create new linked list nodes from sorted values
        for (int val : allValues) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        // Return head of the merged linked list
        return dummy->next;
        
    }
};