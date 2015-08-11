/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 */
ass Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if(!n) return 0;
      int count = 1;
      int prev = nums[0]; // previous number
      int j = 1;
      for(int i = 1; i < n; i++){
	if(nums[i] != prev){
	  count = 1;
	  nums[j++] = nums[i];
	  prev = nums[i];
	}
	else{
	  count++;
	  if(count <= 2)
	    nums[j++] = nums[i];
	}
      }
      return j;
    }
};
