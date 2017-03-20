/*
 * Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 */
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> map;
      for(int i = 0; i<nums.size(); i++){
	if(map[nums[i]] == 0) map[nums[i]] = 1;
	else return true;
      }
      return false;
    }
};

// v2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 11:15 - 11:16
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++) {
            if(set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
        }
        
        return false;
    }
};
