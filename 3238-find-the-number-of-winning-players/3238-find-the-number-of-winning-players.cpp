class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>>mp;
        int count=0;
        for(auto p:pick){
            mp[p[0]].push_back(p[1]);
        }
        for(int i=0;i<n;i++){
            vector<int>temp=mp[i];
            vector<int>freq(11,0);
            for(int x:temp){freq[x]++;}
            int mx=*max_element(freq.begin(),freq.end());
            if(mx>i) count++;
        }
        return count;
    }
};