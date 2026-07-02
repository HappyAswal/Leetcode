class NumArray {
public:
    int seg[4*3*10001];
    int n;
    void build(int idx,int l,int r,vector<int>&nums){
        if(l==r){
            seg[idx]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*idx+1,l,mid,nums);
        build(2*idx+2,mid+1,r,nums);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    void supdate(int idx,int l,int r, int range, int val){
        if(l==r){
            seg[idx]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(range<=mid) supdate(2*idx+1,l,mid,range,val);
        else supdate(2*idx+2,mid+1,r,range,val);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int query(int idx,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return 0;
        if(l>=ql && r<=qr) return seg[idx];
        int mid=l+(r-l)/2;
        int left=query(2*idx+1,l,mid,ql,qr);
        int right=query(2*idx+2,mid+1,r,ql,qr);
        return left+right;
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        supdate(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */