class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int last[256];
      int start = 0, nMax = 0;
      memset(last, -1, sizeof(last));
      int size = s.size();
      for(int i = 0; i < size; i++){
	if(last[s[i]] >= start){
	  start = last[s[i]] + 1;
	}
	nMax = std::max(nMax, i - start + 1);
	last[s[i]] = i;
      }
      return nMax;
    }
};
