/*
 * Given an array containing n distinct numbers taken from 
 * 0, 1, 2, ..., n, find the one that is missing from the array.
 */
class Solution {
  public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size() + 1; // "real" size
      int realsum = n * (n - 1) / 2;
      int sum = 0;
      for(int i = 0; i < n - 1; i++){
	sum += nums[i];
      }
      return realsum - sum;
    }
};
