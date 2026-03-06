class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return false;
        int dip=-1;
        for(int j=1;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1] && arr[j]>arr[j-1]) {dip=j; break;}
        }
        if(dip==-1) return false;
        int i=0;
        while(i<dip){
            if(arr[i]>arr[i+1] || arr[i]==arr[i+1]) return false;
            else i++;
        }
        i=dip;
        while(i<n-1){
            if(arr[i]<arr[i+1] || arr[i]==arr[i+1]) return false;
            else i++;
        }
        return true;
    }
};