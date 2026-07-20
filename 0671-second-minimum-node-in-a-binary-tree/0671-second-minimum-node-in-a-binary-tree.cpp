class Solution {
public:
    long long ans = LLONG_MAX;

    void dfs(TreeNode* root, int mini) {

        if(root == NULL)
            return;

        if(root->val > mini)
            ans = min(ans, (long long)root->val);

        dfs(root->left, mini);
        dfs(root->right, mini);
    }

    int findSecondMinimumValue(TreeNode* root) {

        dfs(root, root->val);

        return (ans == LLONG_MAX) ? -1 : (int)ans;
    }
};