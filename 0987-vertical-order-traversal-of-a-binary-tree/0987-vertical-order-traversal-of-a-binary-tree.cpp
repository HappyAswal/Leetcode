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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0}); // root,-1/+1,lvl
        while(!q.empty()){
            auto x=q.front();
            auto [node,id,lvl]=x;
            q.pop();
            nodes[id][lvl].insert(node->val);
            if(node->left) q.push({node->left,id-1,lvl+1});
            if(node->right) q.push({node->right,id+1,lvl+1});
        }
        vector<vector<int>>ans;
        for(auto& p:nodes){
            vector<int>column;
            for(auto& e:p.second){
                column.insert(column.end(),e.second.begin(),e.second.end());
            }
            ans.push_back(column);
        }  
        return ans;
    }
};