/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 */
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int result = 0;
      int n = prices.size();
      if(n < 2) return 0;
      int mini = prices[0];
      int maxi = prices[n - 1];
      vector<int> premax(n, 0), postmax(n, 0);
      for(int i = 1; i < n; i++){
	mini = min(mini, prices[i]);
	premax[i] = max(premax[i - 1], prices[i] - mini); // all max before i
      }
      for(int i = n - 2; i >= 0; i--){
	maxi = max(maxi, prices[i]);
	postmax[i] = max(postmax[i + 1], maxi - prices[i]);
      }
      for(int i = 0; i < n; i++){
	result = max(result, premax[i] + postmax[i]); // both includes day "i"
      }
      return result;
    }
};
