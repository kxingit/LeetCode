/* 
 * Product of Array Except Self 
 *
 * Given an array of n integers where n > 1, nums, 
 * return an array output such that output[i] is equal 
 * to the product of all the elements of nums except nums[i].
 *
 */
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int size = nums.size();
      vector<int> leftProduct(size, 1);
      for(int i = 1; i < size; i++){ // 1 to n - 1
	leftProduct[i] = leftProduct[i - 1] * nums[i - 1]; // pay attention to index
      }

      int rightProduct = 1;
      for(int i = size - 2; i >= 0; i--){ // n - 2 to 0
	rightProduct = rightProduct * nums[i + 1];
	leftProduct[i] *= rightProduct; // set as return result
      }
      return leftProduct;
    }
};
