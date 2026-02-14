class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto&x:prerequisites){
            int u=x[0];
            int v=x[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        vector<int>topo;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int f=q.front();
            topo.push_back(f);
            q.pop();
            for(auto&nbr:adj[f]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        if(topo.size()==numCourses) return topo;
        else return {};
    }
};