class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int x:rooms[i]){
                adj[i].push_back(x);
            }
        }
        vector<int>vis(n,false);
        vis[0]=true;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front(); q.pop();
            if(adj[node].size()==0) vis[node]=true;
            for(int nbr:adj[node]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false) return false;
        }
        return true;

    }
};