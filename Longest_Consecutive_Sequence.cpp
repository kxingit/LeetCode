/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 */
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size() == 0) return 0;
      unordered_set<int> set;
      int result = 1;
      for(int i = 0; i < nums.size(); i++){
	set.insert(nums[i]);
      }
      for(int i = 1; i < nums.size(); i++){
	int k = 1;
	int len = 1;
	if(set.empty()) break;
	while(set.count(nums[i] + k)){
	  set.erase(nums[i] + k);
	  len++;
	  k++;
	}
	k = 1;
	while(set.count(nums[i] - k)){
	  set.erase(nums[i] - k);
	  len++;
	  k++;
	}
	result = max(result, len);
      }
      return result;
    }
};
// v2
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      int n = nums.size();
      if(!n) return 0;
      unordered_set<int> set;
      int result = 1;
      for(int i = 0; i < n; i++){
	set.insert(nums[i]);
      }
      for(int i = 0; i < n; i++){
	int len = 1;
	int k = 1;
	while(set.count(nums[i] + k)){
	  set.erase(nums[i] + k);
	  len++;
	  k++;
	}
	k = 1;
	while(set.count(nums[i] - k)){
	  set.erase(nums[i] - k);
	  len++;
	  k++;
	}
	result = max(result, len);
      }
      return result;
    }
};
// v3
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> dict;
      for(int i = 0; i < nums.size(); i++) {
	dict.insert(nums[i]);
      }
      int result = 1;
      for(int i = 0; i < nums.size(); i++) {
	int num = nums[i];
	int curlong = 1;
	int temp = num;
	dict.erase(temp);
	while(dict.find(temp + 1) != dict.end()) {
	  curlong++;
	  dict.erase(temp + 1);
	  temp = temp + 1;
	}
	temp = num;
	while(dict.find(temp - 1) != dict.end()) {
	  curlong++;
	  dict.erase(temp - 1);
	  temp = temp - 1;
	}
	result = max(result, curlong);
      }
      return result;
    }
};
