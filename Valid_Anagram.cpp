/*
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
*/
class Solution {
  public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()) return false;

      int count[26] = {0};
      for(int i = 0; i < s.size(); i++){
	count[s[i] - 'a']++;
      }
      for(int i = 0; i < t.size(); i++){
	count[t[i] - 'a']--;
	if(count[t[i] - 'a'] < 0) return false;
      }
      return true;
    }
};
