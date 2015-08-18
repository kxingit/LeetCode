/* Given an array of integers and an integer k, 
 * find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j]
 * and the difference between i and j is at most k.
 */
class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> map;
      int mindis = INT_MAX;
      for(int i = 0; i < nums.size(); i++){
	if(map[nums[i]] == 0) map[nums[i]] = i + 1; // map[nums[i]] - 1 is position
	else mindis = i - (map[nums[i]] - 1);
	map[nums[i]] = i + 1;
	if(mindis <= k) return true;
      }
      return false;
    }
};
