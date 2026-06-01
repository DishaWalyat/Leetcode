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

    int goodNodes(TreeNode* root, int maxi) {

        if(root == NULL)
            return 0;

        int count = 0;

        if(root->val >= maxi)
            count = 1;

        maxi = max(maxi, root->val);

        count += goodNodes(root->left, maxi);
        count += goodNodes(root->right, maxi);

        return count;
    }

    int goodNodes(TreeNode* root) {

        return goodNodes(root, root->val);
    }
};