/*
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * O(n) solution: bucket sort
 */
class Solution {
  public:
    int maximumGap(vector<int>& nums) {
      int n = nums.size();
      if(n < 2) return 0;
      sort(nums.begin(), nums.end());
      int maxGap = 0;
      for(int i = 0; i < n - 1; i++){
	int currGap = abs(nums[i + 1] - nums[i]);
	maxGap = max(maxGap, currGap);
      }
      return maxGap;
    }
};
