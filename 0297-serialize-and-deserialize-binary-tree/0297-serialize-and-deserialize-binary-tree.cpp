/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(node){
                s+=to_string(node->val)+',';
                q.push(node->left);
                q.push(node->right);
            }
            else s+="null,";
        }
        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<string>d;
        string x="";
        for(char c:data){
            if(c==','){
                d.push_back(x);
                x="";
            }
            else x+=c;
        }
        TreeNode* root=new TreeNode(stoi(d[0]));
        queue<TreeNode*>q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(d[i]!="null"){
                node->left=new TreeNode(stoi(d[i]));
                q.push(node->left);
            }
            i++;
            if(d[i]!="null"){
                node->right=new TreeNode(stoi(d[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));