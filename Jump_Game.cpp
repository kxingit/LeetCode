/* 
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 */
class Solution {
  public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      if(!n) return false;
      int maxi = nums[0];
      int i = 0;
      while(i <= maxi && i < n){
	int currMaxi = i + nums[i];
	maxi = max(maxi, currMaxi);
	if(maxi >= n - 1) return true;
	i++;
      }
      return false;
    }
};
