class Solution {
public:

    bool uniformArray(vector<int>& nums1) {
        int x=*min_element(nums1.begin(),nums1.end());
        //check even or odd;
        bool even=false;
        if(x%2==0) even=true;
        //even hum all even bana hi nhi sakte
        //as smallest odd ko even krne ke liye use chota odd nhi mil sakta
        //only possible if all even already
        if(even){
            for(int x:nums1){
                if(x%2!=0) return false;
            }
        }
        //odd hum odd hi try kr sakte hai
        return true;


    }
};