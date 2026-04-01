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
    void solve(TreeNode* root,int ts,int sum,vector<int>&temp){
        if(!root) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==ts){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        solve(root->left,ts,sum,temp);
        solve(root->right,ts,sum,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,0,temp);
        return ans;
    }
};