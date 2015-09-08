/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 */
// greedy
class Solution {
  public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), comp);
      string result;
      for(auto num : nums){
	result += to_string(num);
      }
      for(auto c : result) {
	if(c != '0') return result;
      }
      return "0";
    }
    static bool comp(int a, int b) {
      if(to_string(a) + to_string(b) > to_string(b) + to_string(a))
	return true;
      else 
	return false;
    }
};
