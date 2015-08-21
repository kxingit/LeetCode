/*
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving 
 * the order of characters. No two characters may map to the same character but a character may map to itself.
 */
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, char> s2t;
      unordered_map<char, char> t2s;
      int n = s.size();
      int m = t.size();
      if (n != m) return false;
      for (int i = 0; i < n; i++) {
	if (s2t.find(s[i]) == s2t.end() && t2s.find(t[i]) == t2s.end()) {
	  s2t[s[i]] = t[i];
	  t2s[t[i]] = s[i];
	}
	else if (s2t.find(s[i]) != s2t.end() && t2s.find(t[i]) != t2s.end()) {
	  if(s2t[s[i]] != t[i]) return false;
	}
	else return false; // 2 to 1 mapping
      }
      return true;
    }
};
