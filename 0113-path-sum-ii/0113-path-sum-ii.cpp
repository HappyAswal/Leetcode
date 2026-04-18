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
    vector<vector<int>>ans;
    void solve(TreeNode* root, int targetSum,int sum,vector<int>&temp){
        if(root==nullptr) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum+root->val==targetSum){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        solve(root->left,targetSum,sum+root->val,temp);
        solve(root->right,targetSum,sum+root->val,temp);
        temp.pop_back();
    }   
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,0,temp);
        return ans;
    }
};