class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto&nbr:graph[node]){
                        if(color[nbr]==-1){
                            color[nbr]=1-color[node];
                            q.push(nbr);
                        }
                        else if(color[nbr]==color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};