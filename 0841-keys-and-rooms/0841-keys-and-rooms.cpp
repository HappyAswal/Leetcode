class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,false);
        vis[0]=true;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front(); q.pop();
            for(int nbr:rooms[node]){
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