/*
 * Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 */
class Solution {
  public:
    void reverseWords(string &s) {
      int n = s.size();
      rev(s, 0, n - 1);
      int start = 0, end = 0;
      for(int i = 0; i < n; i++){
	if(s[i] == ' '){ 
	  end = i - 1;
	  rev(s, start, end);
	  start = i + 1;
	}
      }
      rev(s, start, n - 1);
    }
    void rev(string &s, int start, int end){
      while(start < end){
	swap(s[start], s[end]);
	start++;
	end--;
      }
    }
};
