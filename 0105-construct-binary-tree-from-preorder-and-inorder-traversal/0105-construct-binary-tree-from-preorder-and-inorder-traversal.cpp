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
    TreeNode* build(int s,int e,int& idx,vector<int>& preorder, vector<int>& inorder){
        if(s>e) return NULL;
        int r=preorder[idx];
        int mid;
        for(int i=s;i<=e;i++){
            if(inorder[i]==r){
                mid=i;
                break;
            }
        }
        idx++;
        TreeNode* root=new TreeNode(r);
        root->left=build(s,mid-1,idx,preorder,inorder);
        root->right=build(mid+1,e,idx,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        return build(0,n-1,idx,preorder,inorder);
    } 
};