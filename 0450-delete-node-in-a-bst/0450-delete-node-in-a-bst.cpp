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

    TreeNode* findMin(TreeNode* root) {

        while(root->left)
            root = root->left;

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL)
            return NULL;

        if(key < root->val) {

            root->left =
                deleteNode(root->left, key);
        }

        else if(key > root->val) {

            root->right =
                deleteNode(root->right, key);
        }

        else {

            // No child
            if(root->left == NULL &&
               root->right == NULL) {

                delete root;
                return NULL;
            }

            // Only right child
            if(root->left == NULL) {

                TreeNode* temp = root->right;

                delete root;

                return temp;
            }

            // Only left child
            if(root->right == NULL) {

                TreeNode* temp = root->left;

                delete root;

                return temp;
            }

            // Two children

            TreeNode* succ =
                findMin(root->right);

            root->val = succ->val;

            root->right =
                deleteNode(root->right,
                           succ->val);
        }

        return root;
    }
};