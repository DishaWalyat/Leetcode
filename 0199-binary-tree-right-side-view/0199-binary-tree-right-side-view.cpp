class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> q;
        vector<int> level;

        if(root == NULL)
            return level;

        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Rightmost node of current level
                if(i == size - 1) {
                    level.push_back(node->val);
                }

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);
            }
        }

        return level;
    }
};