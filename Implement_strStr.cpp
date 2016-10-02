class Solution {
  public:
    int strStr(string s, string t) {
      if(t.size() == 0) return 0;
      for(int i = 0; i < s.size(); i++) {
	for(int j = 0; j < t.size(); j++) {
	  if(i + t.size() > s.size()) break;
	  if(s[i + j] != t[j]) break;
	  if(j == t.size() - 1){
	    return i;
	  }
	}
      }
      return -1;
    }
};
