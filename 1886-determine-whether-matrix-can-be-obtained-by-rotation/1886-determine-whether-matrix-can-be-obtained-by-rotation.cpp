class Solution {
public:
    int n;
    void rotate(vector<vector<int>>&mat){
        transpose(mat);
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    void transpose(vector<vector<int>>&mat){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n=mat.size();
        if(mat==target) return true;
        for(int i=1;i<=3;i++){
            rotate(mat);
            if(mat==target){return true; break;}
        }
        return false;
    }
};