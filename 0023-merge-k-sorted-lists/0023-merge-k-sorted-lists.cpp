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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-Heap custom node value comparison
    }
};

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom Min-Heap jo Linked List ke Nodes ke addresses store karega
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // Step 1: Saari non-empty lists ke head nodes ko heap me push karo
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(-1); // Dummy node to avoid boundary checks
        ListNode* tail = dummy;

        // Step 2: Ek-ek karke min node nikalo aur uske next ko push karo
        while (!minHeap.empty()) {
            ListNode* topNode = minHeap.top();
            minHeap.pop();

            tail->next = topNode; // Nayi list me joda
            tail = tail->next;

            // Agar us list me aage aur nodes bache hain, toh next node ko queue me daalo
            if (topNode->next != NULL) {
                minHeap.push(topNode->next);
            }
        }

        return dummy->next;
    }
};