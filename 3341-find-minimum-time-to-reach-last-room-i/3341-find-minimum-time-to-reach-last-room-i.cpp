class Solution {
public:
    int minTimeToReach(vector<vector<int>>& movieTime) {
        int n=movieTime.size();
        int m=movieTime[0].size();
        vector<vector<long long>>mint(n,vector<long long>(m,LLONG_MAX));
        priority_queue<tuple<int,int,long long>,vector<tuple<int,int,long long>>,greater<tuple<int,int,long long>>>pq;
        mint[0][0]=0;
        //i,j,time
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        pq.push({0,0,0});
        while(!pq.empty()){
            auto[ci,cj,ctime]=pq.top();
            pq.pop();
            if(ctime>mint[ci][cj]) continue;
            for(int k=0;k<4;k++){
                int ni=ci+dx[k];
                int nj=cj+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    long long ntime;
                    if(ctime<movieTime[ni][nj]){
                        int wait=movieTime[ni][nj]-ctime;
                        ntime=ctime+wait+1;
                    }else if(ctime>=movieTime[ni][nj]){
                        ntime=ctime+1;
                    }
                    if(ntime<mint[ni][nj]){
                        mint[ni][nj]=ntime;
                        pq.push({ni,nj,ntime});
                    }
                }
            }
        }
        return mint[n-1][m-1];
    }
};