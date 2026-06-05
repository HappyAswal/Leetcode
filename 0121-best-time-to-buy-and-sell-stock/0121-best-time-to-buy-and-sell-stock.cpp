class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy_price=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>best_buy_price){
                profit=max(profit,prices[i]-best_buy_price);
            }
            best_buy_price=min(best_buy_price,prices[i]);
        }
        return profit;
    }
};