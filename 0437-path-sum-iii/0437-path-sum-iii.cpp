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
    unordered_map<long long,int>mp;
    int solve(TreeNode* root,int targetSum,long long sum){
        if(!root) return 0;
        sum+=root->val;
        int count=0;
        //need
        long long need=sum-targetSum;
        if(mp.find(need)!=mp.end()){
            count=mp[need];
        }
        mp[sum]++;
        count+=solve(root->left,targetSum,sum);
        count+=solve(root->right,targetSum,sum);
        mp[sum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        return solve(root,targetSum,0);
    }
};