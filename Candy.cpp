/*
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 */
class Solution {
  public:
    int candy(vector<int>& ratings) {
      if (ratings.size() == 0) 
	return 0;

      int candies[2][ratings.size()]; // record from left to right, and from right to left
      candies[0][0] = 1;
      candies[1][ratings.size() - 1] = 1;
      for (int i = 1, j = ratings.size() - 2; i < ratings.size(); i++, j--) {
	candies[0][i] = ratings[i] > ratings[i - 1] ? candies[0][i - 1] + 1 : 1;
	candies[1][j] = ratings[j] > ratings[j + 1] ? candies[1][j + 1] + 1 : 1;
      }

      int sum = 0;
      for (int i = 0; i < ratings.size(); i ++) 
	sum += max(candies[0][i], candies[1][i]);

      return sum;
    }
};
