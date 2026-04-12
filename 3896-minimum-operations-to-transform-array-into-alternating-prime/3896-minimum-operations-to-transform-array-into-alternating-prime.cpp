class Solution {
public:
    bool checkp(int x){
        if(x<=1) return false;
        if(x<=3) return true;
        if(x%2==0 || x%3==0) return false;
        for(int i=3;i*i<=x;i+=2){
            if(x%i==0) return false;
        } 
        return true;
    }
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int nm=nums[i];
            if(i%2==0){
                while(!checkp(nm)){
                    nm++;
                    count++;
                }
            }else{
                while(checkp(nm)){
                    nm++;
                    count++;
                }
            }
        }
        return count++;
    }
};