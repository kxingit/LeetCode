/*
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 */
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> result;
      deque<int> q; // save indeces of largest numbers
      for(int i = 0; i < nums.size(); i++){
	if(!q.empty() && q.front() == i - k) q.pop_front(); // remove the 1st
	while(!q.empty() && nums[i] > nums[q.back()]) q.pop_back(); // remove smaller
	q.push_back(i); // save the largest to the end
	if(i >= k - 1) result.push_back(nums[q.front()]);
      }
      return result;
    }
};;
