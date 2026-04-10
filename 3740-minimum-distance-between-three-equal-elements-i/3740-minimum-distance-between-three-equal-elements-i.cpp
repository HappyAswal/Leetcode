class Solution {
public:
    int minimumDistance(vector<int>& num) {
        int n=num.size();
        //unordered_map<int,int>mp;
        vector<vector<int>>nums;
        for(int i=0;i<n;i++) nums.push_back({num[i],i});
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int count=1;
            vector<int>index;
            index.push_back(nums[i][1]);
            for(int j=i+1;j<n;j++){
                if(nums[i][0]==nums[j][0] && count<4){
                    count++;
                    index.push_back(nums[j][1]);
                }
            }
            //calculate
            if(index.size()>=3){
                for(int k=0;k+2<index.size();k++){
                    int a=index[k],b=index[k+1],c=index[k+2];
                    int cal=abs(a-b)+abs(b-c)+abs(c-a);
                    ans=min(ans,cal);
                }
            }
        }   
        return (ans==INT_MAX)?-1:ans;
    }
};