class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprices = INT_MAX, maxprofit = 0;
        for(int price : prices){
            maxprofit = max(maxprofit, price - minprices);
            minprices = min(price, minprices);
        }
        return maxprofit;
    }
};