/*
 * O(n) can AC
 * int search(vector<int>& nums, int target) {
 *      for(int i = 0; i < nums.size(); i++){
 *          if(nums[i] == target) return i;
 *      }
 *      return -1;
 *  }
 */

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      return searchHelper(nums, 0, nums.size() - 1, target);
    }
    int searchHelper(vector<int>& nums, int s, int e, int target){
      if(s == e && nums[s] == target) return s;
      if(s == e && nums[s] != target) return -1;
      if(s > e) return -1;
      int mid = (s + e) / 2;
      if(target == nums[mid]) return mid;
      if(nums[mid] >= nums[s]){ // first half is in right order. <: X
	if(target >= nums[s] && target < nums[mid])
	  return searchHelper(nums, s, mid - 1, target);
	else
	  return searchHelper(nums, mid + 1, e, target);
      }
      else{
	if(target > nums[mid] && target <= nums[e])
	  return searchHelper(nums, mid + 1, e, target);
	else
	  return searchHelper(nums, s, mid - 1, target);
      }
    }
};
