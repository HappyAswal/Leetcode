class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int curr_buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>curr_buy){
                profit=max(profit,prices[i]-curr_buy);
            }
            curr_buy=min(curr_buy,prices[i]);
        }
        return profit;
    }
};