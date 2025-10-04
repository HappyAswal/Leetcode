class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int currA=min(height[i],height[j])*(j-i);
            maxA=max(maxA,currA);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxA;
    }
};