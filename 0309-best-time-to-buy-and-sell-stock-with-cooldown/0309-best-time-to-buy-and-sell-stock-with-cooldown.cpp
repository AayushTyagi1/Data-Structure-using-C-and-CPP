class Solution {
public:
    int maxProfit(vector<int>& prices) {
          int buy(INT_MAX), sell(0), prev_sell(0), prev_buy;
          for (int price : prices) {
              prev_buy = buy;
              buy = min(buy,price-prev_sell);
              prev_sell = sell;
              sell = max(sell,price-prev_buy);
          }
          return sell;
    }
};  