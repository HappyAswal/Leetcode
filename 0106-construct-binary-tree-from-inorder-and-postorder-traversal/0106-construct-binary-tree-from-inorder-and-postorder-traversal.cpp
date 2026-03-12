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
    TreeNode* build(int s,int e,int& idx,vector<int>& inorder, vector<int>& postorder){
        if(s>e) return NULL;
        int r=postorder[idx];
        TreeNode* root=new TreeNode(r);
        int mid;
        for(int i=s;i<=e;i++){
            if(inorder[i]==r){
                mid=i;
                break;
            }
        }
        idx--;
        root->right=build(mid+1,e,idx,inorder,postorder);
        root->left=build(s,mid-1,idx,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int idx=n-1;
        return build(0,n-1,idx,inorder,postorder);
    }
};