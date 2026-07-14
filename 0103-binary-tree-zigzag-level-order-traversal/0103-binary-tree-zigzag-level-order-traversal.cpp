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

    // Stores the final zigzag traversal
    vector<vector<int>> ans;

    // If tree is empty, return empty answer
    if(root == NULL)
        return ans;

    // Queue for normal level order traversal (BFS)
    queue<TreeNode*> q;
    q.push(root);

    // true  -> Left to Right
    // false -> Right to Left
    bool leftToRight = true;

    // Process level by level
    while(!q.empty()){

        // Number of nodes in current level
        int size = q.size();

        // Stores current level
        vector<int> level;

        // Traverse all nodes of current level
        while(size--){

            TreeNode* node = q.front();
            q.pop();

            // Store current node
            level.push_back(node->val);

            // Push children for next level
            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }

        // Reverse only if direction is Right to Left
        if(!leftToRight)
            reverse(level.begin(), level.end());

        // Store this level
        ans.push_back(level);

        // Change direction for next level
        leftToRight = !leftToRight;
    }

    return ans;
}
};