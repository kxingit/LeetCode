/* 
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
 * The algorithm should run in linear time and in O(1) space.
 * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 */
class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> result;
      int n = nums.size();
      if(n <= 1) return nums;
      if(n == 2) {
	if(nums[0] != nums[1]) return nums;
	else {
	  result.push_back(nums[0]);
	  return result;
	}
      }

      vector<int> cand(2, 0); // candidates
      vector<int> count(2, 0); 
      vector<int> checkcount(2, 0); 
      for(int i = 0; i < n; i++){
	if(!count[0]) {
	  cand[0] = nums[i];
	}
	else if(!count[1]) {
	  cand[1] = nums[i];
	}
	if(cand[0] == nums[i])
	  count[0]++;
	else if(cand[1] == nums[i])
	  count[1]++;
	else {
	  count[0]--;
	  count[1]--;
	}
      }
      // need to check candidates!
      for(int i = 0; i < 2; i++) {
	for(int j = 0; j < n; j++) {
	  if(cand[i] == nums[j]) checkcount[i]++;
	}
      }
      if(cand[0] == cand[1] && checkcount[0] > n / 3) {
	result.push_back(cand[0]);
      }
      else {
	for(int i = 0; i < 2; i++)
	  if(checkcount[i] > n /3 ) result.push_back(cand[i]);
      }
      return result;
    }
};
