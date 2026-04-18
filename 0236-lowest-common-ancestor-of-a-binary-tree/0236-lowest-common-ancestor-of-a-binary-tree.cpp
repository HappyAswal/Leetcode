/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode* l=solve(root->left,p,q);
        TreeNode* r=solve(root->right,p,q);
        if(l!=NULL && r!=NULL) return root;
        else if(l!=NULL) return l; //r is null that means value not found
        else return r;   // no value found in l
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};