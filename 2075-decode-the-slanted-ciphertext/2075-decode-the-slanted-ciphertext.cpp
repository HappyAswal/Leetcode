class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;
        vector<vector<char>>matrix(rows,vector<char>(col));
        int idx=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=encodedText[idx];
                idx++;
            }
        }
        string ans="";
        for(int c=0;c<col;c++){
            int i=0,j=c;
            while(i<rows && j<col){
                ans+=matrix[i][j];
                i++,j++;
            }
        }
        while(!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};