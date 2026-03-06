class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                int count=1;
                int j=i;
                while(j>0 && arr[j]>arr[j-1]){
                    count++;
                    j--;
                }
                j=i;
                while(j<arr.size()-1 && arr[j]>arr[j+1]){
                    count++;
                    j++;
                }
                ans=max(count,ans);
            }
        }
        return ans;
    }
};