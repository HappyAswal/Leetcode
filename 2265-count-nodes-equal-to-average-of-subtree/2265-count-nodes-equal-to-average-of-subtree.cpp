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
    int count=0;
    pair<int,int> fxn(TreeNode* root){
        if(!root) return {0,0};
        auto [ls,lc]=fxn(root->left);
        auto [rs,rc]=fxn(root->right);
        int sum=ls+rs+root->val;
        int nodes=lc+rc+1;
        int avg=sum/nodes;
        if(root->val==avg) count++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        fxn(root);
        return count;
    }
};