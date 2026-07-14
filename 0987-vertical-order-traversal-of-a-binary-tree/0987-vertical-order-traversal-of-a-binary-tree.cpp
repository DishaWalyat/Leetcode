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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

    map<int, map<int, multiset<int>>> mp;

    queue<pair<TreeNode*, pair<int,int>>> q;

    q.push({root,{0,0}});

    while(!q.empty()){

        auto temp = q.front();
        q.pop();

        TreeNode* node = temp.first;
        int row = temp.second.first;
        int col = temp.second.second;

        mp[col][row].insert(node->val);

        if(node->left)
            q.push({node->left,{row+1,col-1}});

        if(node->right)
            q.push({node->right,{row+1,col+1}});
    }

    vector<vector<int>> ans;

    for(auto col : mp){

        vector<int> vertical;

        for(auto row : col.second){

            vertical.insert(vertical.end(),
                            row.second.begin(),
                            row.second.end());
        }

        ans.push_back(vertical);
    }

    return ans;
}
};