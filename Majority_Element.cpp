/*
 * Given an array of size n, find the majority element. 
 * The majority element is the element that appears more than n/2 times.
 */
class Solution {
  public:
    int majorityElement(vector<int> &num) {
      unordered_map<int, int> count;
      for (size_t i = 0; i < num.size(); i++) {
	count[num[i]]++;
	if (count[num[i]] > num.size() / 2) return num[i];
      }
    }
};

// O(1) space solution
class Solution {
  public:
    int majorityElement(vector<int> &num) {
      int candidate;
      int count = 0;
      for (size_t i = 0; i < num.size(); i++) {
	if(count == 0){
	  candidate = num[i];
	  count++;
	}
	else if(candidate == num[i]){
	  count++;
	}
	else{
	  count--;
	}
      }
      return candidate;
    }
};
// v3
class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      int cand = nums[0];
      int count = 0;
      for(int i = 0; i < nums.size(); i++) {
	if(nums[i] == cand) count++;
	else {
	  count--;
	  if(count < 0) {
	    cand = nums[i];
	    count = 1;
	  }
	}
      }
      return cand;
    }
};
