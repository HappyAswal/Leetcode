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
    vector<int>val;
    void fxn(TreeNode* root){
        if(!root) return;
        fxn(root->left);
        val.push_back(root->val);
        fxn(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        fxn(root);
        int n=val.size();
        int i=0,j=n-1;
        while(i<j){
            int sum=val[i]+val[j];
            if(sum==k) return true;
            if(sum<k) i++;
            else j--;
        }
        return false;
    }
};