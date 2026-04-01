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
    pair<int,int> dfs(TreeNode* node){
        if(node==NULL) return{0,0};
        auto left=dfs(node->left);
        auto right=dfs(node->right);
        int notake=0+max(left.second,left.first)+max(right.second,right.first);
        int take=node->val+left.first + right.first;
        return {notake,take};
    }
    int rob(TreeNode* root) {
        auto res=dfs(root);
        return max(res.first,res.second);
    }
};