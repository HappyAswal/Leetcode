class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n=arr.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                idx=i;
                break;
            }
        }
        vector<int>ans;
        //case 1
        if(idx==0){
            for(int i=0;i<n;i++){
                ans.push_back(arr[i]*arr[i]);
            }
            return ans;
        }
        //case 2
        if(idx==-1){
            for(int i=n-1;i>=0;i--){
                ans.push_back(arr[i]*arr[i]);
            }
            return ans;
        }
        int l=idx-1;
        int r=idx;
        while(l>=0 && r<n){
            if(abs(arr[l])<abs(arr[r])){
                ans.push_back(arr[l]*arr[l]);
                l--;
            }
            else if(abs(arr[l])>abs(arr[r])){
                ans.push_back(arr[r]*arr[r]);
                r++;
            }else{
                ans.push_back(arr[l]*arr[l]);
                ans.push_back(arr[l]*arr[l]);
                l--;
                r++;
            }
        }
        while(r<n){
            ans.push_back(arr[r]*arr[r]);
            r++;   
        }
        while(l>=0){
            ans.push_back(arr[l]*arr[l]);
            l--;
        }
        return ans;
    }
};