/*
 * Design and implement a TwoSum class. It should support the following operations: add and find.
 * add(1); add(3); add(5);
 * find(4) -> true
 * find(7) -> false
 */ 
// Time Limit Exceeded: sort
class TwoSum {
  public:
    vector<int> nums;
    void add(int number) {
      nums.push_back(number);
      sort(nums.begin(), nums.end());
    }

    bool find(int value) {
      int i = 0, j = nums.size() - 1;
      while(i <= j){
	if(nums[i] + nums[j] == value){
	  return true;
	}
	else if(nums[i] + nums[j] > value){
	  j--;
	}
	else{
	  i++;
	}
      }
      return false;
    }
};
// use hash
class TwoSum {
  public:
    unordered_map<int, int> map;
    void add(int number) {
      map[number]++;
    }

    bool find(int value) {
      for(auto i : map){
	int num1 = i.first;
	int num2 = value - num1;
	if(map.find(num2) != map.end()){ // need to use "find" before checking value
	  if(num1 == num2 && map[num2] > 1)
	    return true;
	  else if(num1 != num2 && map[num2] > 0)
	    return true;
	}
      }
      return false;
    }
};
