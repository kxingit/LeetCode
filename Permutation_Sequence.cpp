/*
 * tag
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 */
class Solution {
  public:
    string getPermutation(int n, int k) {
      vector<int> nums(n, 0);
      int permCount =1;  
      for(int i = 0; i < n; i++){
	nums[i] = i + 1;
	permCount *= (i + 1);
      }
      k--;
      string result;
      for(int i = 0; i < n; i++){
	permCount = permCount / (n - i);
	int choosed = k / permCount;
	result.push_back(nums[choosed] + '0');
	for(int j = choosed; j < n - 1; j++){
	  nums[j] = nums[j + 1];
	}
	k = k % permCount;
      }
      return result;
    }
};
