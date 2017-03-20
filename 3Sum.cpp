class Solution {
  public:
    vector<vector<int> > threeSum(vector<int> &num) {
      int n = num.size();
      sort(num.begin(), num.end());
      vector<vector<int> > res;
      for(int i = 0; i < n-2; i++)
      {
	if(i > 0 && num[i] == num[i-1])continue;
	int target2 = 0 - num[i]; 
	twoSum(num, i+1, target2, res);
      }
      return res;
    }
    void twoSum(vector<int> &sortedNum, int start, int target, vector<vector<int> >&res)
    {
      int head = start, tail = sortedNum.size() - 1;
      while(head < tail)
      {
	int tmp = sortedNum[head] + sortedNum[tail];
	if(tmp < target)
	  head++;
	else if(tmp > target)
	  tail--;
	else
	{ ;
	  res.push_back(vector<int>{sortedNum[start-1], sortedNum[head], sortedNum[tail]});

	  int k = head+1;
	  while(k < tail && sortedNum[k] == sortedNum[head])k++;
	  head = k;

	  k = tail-1;
	  while(k > head && sortedNum[k] == sortedNum[tail])k--;
	  tail = k;
	}
      }
    }
};

// v2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 10:30 - 10:42
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int gap = -nums[i];
            int l = i + 1, r = n - 1;
            while(l < r) {
                if(l > i + 1 && nums[l] == nums[l - 1]) {
                    l++;
                    continue;
                }
                if(nums[l] + nums[r] == gap) {
                    vector<int> solution;
                    solution.push_back(nums[i]);
                    solution.push_back(nums[l]);
                    solution.push_back(nums[r]);
                    res.push_back(solution);
                    l++;
                } else if(nums[l] + nums[r] > gap) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        
        return res;
    }
};
