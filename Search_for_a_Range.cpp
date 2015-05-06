class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int is = 0, ie = nums.size() - 1, im;
      // if(is > ie)  return vector<int>{-1,-1};
      // find one position
      while(is <= ie){
	im = (is + ie) / 2;
	if(nums[im] > target) ie = im - 1;
	else if (nums[im] < target) is = im + 1;
	else break;
      }
      // find range
      if(target != nums[im]) return vector<int>{-1, -1};
      int il = im, ir = im;
      while(nums[il] == target && il >= is) il--;
      while(nums[ir] == target && ir <= ie) ir++;

      return vector<int>{il + 1, ir - 1};
    }
};
