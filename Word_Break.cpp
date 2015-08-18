/*
 * Given a string s and a dictionary of words dict, 
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 */
class Solution {
  public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
      s = ' ' + s; // add dummy 
      int n = s.size();
      vector<bool> kSeg(n, 0); // kSeg[i]: [0 to i] can be segmented
      kSeg[0] = 1;
      for(int i = 1; i < s.size(); i++){
	for(int k = 0; k < i; k++){
	  kSeg[i] = kSeg[k] && wordDict.find(s.substr(k + 1, i - k)) != wordDict.end();
	  if(kSeg[i]) break; // found true, set true
	}
      }
      return kSeg[n - 1];
    }
};
