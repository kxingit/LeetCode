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
// v2
class Solution {
  public:
    bool canPermutePalindrome(string s) {
      map<char, int> dict;
      for(auto c : s) {
	dict[c]++;
      }
      int nOdd = 0; // number of odd char
      for(auto i : dict){
	if(i.second % 2 == 1) nOdd++;
      }
      if(nOdd == 0 || nOdd == 1) return true;
      else return false;
    }
};
