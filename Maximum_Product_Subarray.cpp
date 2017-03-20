/*
 * Find the contiguous subarray within an array (containing at least one number) 
 * which has the largest product.
 */
class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      if(!n) return 0;
      vector<int> dpmin(n, 0);
      vector<int> dpmax(n, 0);
      dpmin[0] = nums[0];
      dpmax[0] = nums[0];
      int result = dpmax[0];
      for(int i = 1; i < n; i++) {
	dpmin[i] = min(dpmax[i - 1] * nums[i], min(nums[i], dpmin[i - 1] * nums[i]));
	dpmax[i] = max(dpmax[i - 1] * nums[i], max(nums[i], dpmin[i - 1] * nums[i]));
	result = max(result, dpmax[i]);
      }
      return result;
    }
};
// v2: rolling array
class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      int n = nums.size();
      if(!n) return 0;
      int dpmin = nums[0];
      int dpmax = nums[0];
      int result = dpmax;
      for(int i = 1; i < n; i++) {
	int tempmin = dpmin; int tempmax = dpmax;
	dpmin = min(tempmax * nums[i], min(nums[i], tempmin * nums[i]));
	dpmax = max(tempmax * nums[i], max(nums[i], tempmin * nums[i]));
	result = max(result, dpmax);
      }
      return result;
    }
};

// v3
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 11:21 - 11:26
        int n = nums.size();
        int mindp[n + 1];
        int maxdp[n + 1];
        mindp[0] = 1;
        maxdp[0] = 1;
        int res = INT_MIN;
        
        for(int i = 1; i <= n; i++) {
            mindp[i] = min(nums[i - 1], min(mindp[i - 1] * nums[i - 1], maxdp[i - 1] * nums[i - 1]));
            maxdp[i] = max(nums[i - 1], max(mindp[i - 1] * nums[i - 1], maxdp[i - 1] * nums[i - 1]));
            res = max(res, maxdp[i]);
        }
        
        return res;
    }
};
