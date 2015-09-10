/*
 * Given an array of n integers nums and a target, find the number of index triplets i, j, k 
 * with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 */
class Solution {
  public:
    int threeSumSmaller(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int result = 0;
      for(int i = 0; i < n; i++){
	int j = i + 1, k = n - 1;
	while(j < k){
	  int sum = nums[i] + nums[j] + nums[k];
	  if(sum >= target){ 
	    k--;
	  }
	  else {
	    result += k - j;
	    j++;
	  }
	}
      }
      return result;
    }
};
// v2
class Solution {
  public:
    int threeSumSmaller(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int result = 0;
      for(int i = 0; i < nums.size(); i++) {
	int j = i + 1, k = nums.size() - 1;
	while(j < k) {
	  int sum = nums[i] + nums[j] + nums[k];
	  if(sum >= target){
	    k--;
	  }
	  else{
	    result += k - j;
	    j++;
	  }
	}
      }
      return result;
    }
};
