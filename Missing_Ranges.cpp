/*
 * tag
 * Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
 *  For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
 */
class Solution {
  public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
      vector<string> res;
      const int size_n = nums.size();
      int start = lower;
      for (int i = 0; i < size_n;) {
	while (i < size_n && start == nums[i]) { i++; start++;}
	if (start >= upper + 1) return res;
	if (i == size_n) break;
	res.push_back(getRange(start, nums[i] - 1));
	start = nums[i];
      }
      if (nums.empty() || nums[size_n - 1] < upper) {
	res.push_back(getRange(start, upper));
      }
      return res;
    }
    string getRange(int start, int end) {
      string str = to_string(start);
      if (start < end) str += "->" + to_string(end);
      return str;
    }
};
