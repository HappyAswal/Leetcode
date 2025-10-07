class Solution {
public:
    int trap(vector<int>& height) {
        int lmax=0,rmax=0,water=0;
        int lp=0,rp=height.size()-1;
        while(lp<rp){
            if(height[lp] <= height[rp]){
                if(lmax>height[lp]){
                    water+=lmax-height[lp];
                }else{
                    lmax=height[lp];
                }lp=lp+1;
            }else{
                if(rmax>height[rp]){
                    water+=rmax-height[rp];
                }else{
                    rmax=height[rp];
                }
                rp=rp-1;
            }
        }return water;
    }
};