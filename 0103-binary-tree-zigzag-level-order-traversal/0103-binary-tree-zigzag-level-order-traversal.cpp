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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //this is an example of BFS + Queue
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        if ( root == NULL) return ans;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int size= q.size();

            vector<int> level (size);

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                if( node -> left != NULL) q.push(node->left);
                if (node-> right != NULL) q.push(node->right);

                q.pop();

                int index;

                if(leftToRight)
                    index = i;
                else
                    index = size - 1 - i;

                level[index] = node->val;
            }
            ans.push_back(level);

            leftToRight = !leftToRight;


        }

        return ans;

        
    }
};