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
    vector<TreeNode*> solve(int start,int end){
        vector<TreeNode*>res;
        if(start>end) return {NULL};
        if(start==end){
            TreeNode* t = new TreeNode(start);
            return {t};
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>ls=solve(start,i-1);
            vector<TreeNode*>rs=solve(i+1,end);
            for(auto&x:ls){
                for(auto&y:rs){
                    TreeNode* tr=new TreeNode(i);
                    tr->left=x;
                    tr->right=y;
                    res.push_back({tr});
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};