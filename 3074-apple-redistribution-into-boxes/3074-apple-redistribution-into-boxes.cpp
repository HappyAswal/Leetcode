class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int total_apple=accumulate(apple.begin(),apple.end(),0);
        int count=0;
        int i=0;
        while(total_apple > 0){
            total_apple-=capacity[i];
            count++;
            i++;
        }
        return count;

    }
};