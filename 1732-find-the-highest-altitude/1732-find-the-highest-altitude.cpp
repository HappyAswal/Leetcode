class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currh=0;
        int maxalt=currh;
        for(int alt:gain){
            currh+=alt;
            maxalt=max(currh,maxalt);
        }
        return  maxalt;
    }
};