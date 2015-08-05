/* 
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, 
 * not the kth distinct element.
 *
 * Improve: https://en.wikipedia.org/wiki/Quickselect#Time_complexity
 * average O(n)
 */

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      return nums[nums.size() - k];
    }
};
