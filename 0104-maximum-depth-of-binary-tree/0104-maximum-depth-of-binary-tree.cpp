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
    int ddpa(TreeNode* root){
        if(root==NULL) return 0;
        int l=ddpa(root->left);
        int r=ddpa(root->right);
        return max(l,r)+1;
    }
    int maxDepth(TreeNode* root) {
        return ddpa(root);
    }
};