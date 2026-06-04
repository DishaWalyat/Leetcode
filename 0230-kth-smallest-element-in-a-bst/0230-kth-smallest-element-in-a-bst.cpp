/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (curr != NULL || !s.empty()) {
            // 1. Go as deep left as possible, pushing nodes to the stack
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            
            // 2. Process the top node (current smallest available)
            curr = s.top();
            s.pop();
            
            k--; // We visited a node, so decrement k
            if (k == 0) {
                return curr->val; // Found the k-th smallest!
            }
            
            // 3. Move to the right subtree
            curr = curr->right;
        }
        
        return -1; // Fallback if k is out of bounds
    }
};