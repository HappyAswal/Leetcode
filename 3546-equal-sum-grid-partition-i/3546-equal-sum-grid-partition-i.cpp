class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<long long>prefixrows;
        vector<long long>prefixcols;
        for(int down=0;down<cols;down++){
            long long sum=0;
            for(int i=0;i<rows;i++){
                sum+=grid[i][down];
            }
            prefixcols.push_back(sum);
        }
        for(int right=0;right<rows;right++){
            long long sum=0;
            for(int i=0;i<cols;i++){
                sum+=grid[right][i];
            }
            prefixrows.push_back(sum);
        }
        long long total1=accumulate(prefixrows.begin(),prefixrows.end(),0LL);
        long long ctotal1=0;
        for(int i=0;i<rows-1;i++){
            ctotal1+=prefixrows[i];
            if(ctotal1*2==total1) return true;
        }
        long long total2=accumulate(prefixcols.begin(),prefixcols.end(),0LL);
        long long ctotal2=0;
        for(int i=0;i<cols-1;i++){
            ctotal2+=prefixcols[i];
            if(ctotal2*2==total2) return true;
        }
        return false;
    }
};