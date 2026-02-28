class Solution {
public:
    int minTimeToReach(vector<vector<int>>& movieTime) {
        int n=movieTime.size();
        int m=movieTime[0].size();
        vector<vector<long long>>mint(n,vector<long long>(m,LLONG_MAX));
        priority_queue<tuple<long long,int,int,int>,
            vector<tuple<long long,int,int,int>>,
            greater<tuple<long long,int,int,int>>
        >pq;
        mint[0][0]=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        pq.push({0,1,0,0});
        while(!pq.empty()){
            auto[ctime,move,ci,cj]=pq.top();
            pq.pop();
            if(ctime>mint[ci][cj]) continue;
            for(int k=0;k<4;k++){
                int ni=ci+dx[k];
                int nj=cj+dy[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    long long ntime;
                    if(ctime<movieTime[ni][nj]){
                        int wait=movieTime[ni][nj]-ctime;
                        ntime=ctime+wait+move;
                    }else if(ctime>=movieTime[ni][nj]){
                        ntime=ctime+move;
                    }
                    if(ntime<mint[ni][nj]){
                        mint[ni][nj]=ntime;
                        if(move==1){
                            pq.push({ntime,2,ni,nj});
                        }else if(move==2){
                            pq.push({ntime,1,ni,nj});
                        }
                    }
                }
            }
        }
        return mint[n-1][m-1];
    }
};