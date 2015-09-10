/*
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 */
class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      if(!n) return -1;
      if(n == 1) return 0;
      int i = 0, j = n - 1;
      while(i + 1 < j){
	int mid = (i + j) / 2;
	if(nums[mid] > nums[mid + 1]) j = mid;
	else i = mid;
      }
      return nums[i] > nums[j] ? i : j;
    }
};
