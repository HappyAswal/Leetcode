class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>rev(n);
        vector<int>outdegree(n,0);
        vector<bool>safe(n,false);

        for(int i=0;i<n;i++){
            for(auto&nbr:graph[i]){
                rev[nbr].push_back(i);
            }
            outdegree[i]=graph[i].size();
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe[node]=true;
            for(auto&nbr:rev[node]){
                outdegree[nbr]--;
                if(outdegree[nbr]==0) q.push(nbr);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};