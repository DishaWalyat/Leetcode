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

    struct NodeValue{

        bool isBST;
        int sum;
        int mini;
        int maxi;

        NodeValue(bool bst,int s,int mn,int mx){
            isBST=bst;
            sum=s;
            mini=mn;
            maxi=mx;
        }
    };

    int ans=0;

    NodeValue solve(TreeNode* root){

        if(root==NULL)
            return NodeValue(true,0,INT_MAX,INT_MIN);

        NodeValue left=solve(root->left);
        NodeValue right=solve(root->right);

        if(left.isBST && right.isBST &&
           left.maxi<root->val &&
           root->val<right.mini){

            int currSum=left.sum+right.sum+root->val;

            ans=max(ans,currSum);

            return NodeValue(
                true,
                currSum,
                min(left.mini,root->val),
                max(right.maxi,root->val)
            );
        }

        return NodeValue(false,0,0,0);
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};