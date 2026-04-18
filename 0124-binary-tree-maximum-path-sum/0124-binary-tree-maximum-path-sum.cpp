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
    int maxp=INT_MIN;
    int solve(TreeNode*root){
        if(!root) return 0;
        int l=max(0,solve(root->left));
        int r=max(0,solve(root->right));
        maxp=max(maxp,l+r+root->val);
        return max(l,r)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxp;
    }
};