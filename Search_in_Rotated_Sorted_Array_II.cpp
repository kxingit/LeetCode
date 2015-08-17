/*
 * What if duplicates are allowed?
 */
class Solution {
  public:
    bool search(vector<int>& nums, int target) {
      return searchHelper(nums, 0, nums.size() - 1, target);
    }
    int searchHelper(vector<int>& nums, int s, int e, int target){
      if(s == e && nums[s] == target) return true;
      if(s == e && nums[s] != target) return false;
      if(s > e) return false;
      int mid = (s + e) / 2;
      if(target == nums[mid]) return true;
      if(nums[mid] > nums[s]){ 
	if(target >= nums[s] && target < nums[mid])
	  return searchHelper(nums, s, mid - 1, target);
	else
	  return searchHelper(nums, mid + 1, e, target);
      }
      else if(nums[mid] < nums[s]){
	if(target > nums[mid] && target <= nums[e])
	  return searchHelper(nums, mid + 1, e, target);
	else
	  return searchHelper(nums, s, mid - 1, target);
      }
      else{
	return searchHelper(nums, s + 1, e, target); // if[s] = [e], continue
      }
    }
};
