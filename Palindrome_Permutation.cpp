/*
 * Given a string, determine if a permutation of the string could form a palindrome.
 */
class Solution {
  public:
    bool canPermutePalindrome(string s) {
      int n = s.size();
      if(!n) return true;
      char c = s[0];
      for(int i = 1; i < s.size(); i++){
	c ^= s[i];
      }
      if(n % 2 == 0 && c == 0) return true; // even
      else {
	int ccount = 0;
	for(auto curr : s){
	  if(c == curr) ccount++;
	}
	if(ccount % 2) return true;
	else return false;
      }
    }
};
