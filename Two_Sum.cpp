class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
      unordered_map<int, int> mapping;
      vector<int> result;
      for (int i = 0; i < numbers.size(); i++){
	mapping[numbers[i]] = i;
      }
      for (int i = 0; i < numbers.size(); i++){
	const int gap = target - numbers[i];
	if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
	  result.push_back(i+1);
	  result.push_back(mapping[gap] + 1);
	  break;
	}
      }
      return result;
    }
};
// index change
class Solution {
  public:
	vector<int> twoSum(vector<int>& numbers, int target) {
	  unordered_map<int, int> mapping;
	  vector<int> result;
	  for (int i = 0; i < numbers.size(); i++){
		mapping[numbers[i]] = i;
	  }
	  for (int i = 0; i < numbers.size(); i++){
		const int gap = target - numbers[i];
		if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
		  result.push_back(i);
		  result.push_back(mapping[gap]);
		  break;
		}
	  }
	  return result;
	}
};
// optimization
class Solution {
  public:
	vector<int> twoSum(vector<int>& nums, int target) {
	  vector<int> result;
	  unordered_map<int, int> map;
	  for(int i = 0; i < nums.size(); i++) {
		int gap = target - nums[i];
		if(map.find(gap) != map.end()) {
		  result.push_back(i);
		  result.push_back(map[gap]);
		  break;
		}
		map[nums[i]] = i;
	  }
	  return result;
	}
};
