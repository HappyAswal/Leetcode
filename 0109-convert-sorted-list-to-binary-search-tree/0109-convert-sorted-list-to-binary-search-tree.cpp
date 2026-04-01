/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(int start,int end,vector<int>&arr){
        if(start>end) return NULL;
        int mid=start+(end-start)/2;
        TreeNode* node=new TreeNode(arr[mid]);
        node->left=build(start,mid-1,arr);
        node->right=build(mid+1,end,arr);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        vector<int>arr;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        return build(0,n-1,arr);
    }
};