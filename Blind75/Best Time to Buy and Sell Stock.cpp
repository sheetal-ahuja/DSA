class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = INT_MAX;
        for(int it: prices){
            minprice =min(minprice, it);
            maxprofit = max(maxprofit, it-minprice);
        }
        return maxprofit;
    }
};