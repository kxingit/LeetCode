/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 */
class Solution {
  public:
    bool isPalindrome(string s) {
      int i = 0;
      int j = s.size() - 1;
      while(i < j){
	while(i < s.size() && !isAlpha(s[i])) i++;
	while(j >= 0 && !isAlpha(s[j])) j--;
	if(i > j) break;
	if(s[i] != s[j] && s[i] - 'a' != s[j] - 'A' && s[i] - 'A' != s[j] - 'a') 
	  return false;
	i++;
	j--;
      }
      return true;
    }
    bool isAlpha(char c){
      if(c >= '0' && c <= '9') return true;
      if(c >= 'a' && c <= 'z') return true;
      if(c >= 'A' && c <= 'Z') return true;
      return false;
    }
};
