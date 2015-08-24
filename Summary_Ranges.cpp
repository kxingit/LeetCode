/*
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */
class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> result;
      int n = nums.size();
      int i = 0, k = 1; // k: length
      int start, end;
      while(i + k < n){
	start = nums[i];
	end = nums[i];
	while(nums[i] + k == nums[i + k]){
	  k++;
	}
	end = nums[i + k - 1];
	string range;
	if(k == 1){
	  range = to_string(nums[i]);
	  result.push_back(range);
	}
	else if(k > 1){
	  range = to_string(start) + "->" + to_string(end);
	  result.push_back(range);
	}
	i = i + k;
	k = 1;
      }
      if(i == n - 1){
	string range;
	range += to_string(nums[n - 1]);
	result.push_back(range);
	return result;
      }
      return result;
    }
};
