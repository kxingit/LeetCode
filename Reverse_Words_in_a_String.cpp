/*
 * Given an input string, reverse the string word by word.
 */
class Solution {
  public:
    void reverseWords(string &s) {
      if(s.size() == 0) return;
      while(s[0] == ' '){ 
	s.erase(0, 1);
      }
      reverse(s, 0, s.size() - 1);
      if(s.size() == 0) return;
      while(s[0] == ' '){ 
	s.erase(0, 1);
      }
      int start = 0, end = s.size() - 1; // range of a word
      int i = 0;
      for(; i < s.size(); i++){
	if(s[i] == ' '){ 
	  end = i - 1;
	  reverse(s, start, end);
	  start = i + 1;
	}
      }
      end = s.size() - 1; // the last word ends at s.size() - 1
      reverse(s, start, end);
      i = 0;
      while(i < s.size() - 1){
	if(s[i] == ' ' && s[i + 1] == ' '){
	  s.erase(i + 1, 1);
	  i--;
	}
	i++;
      }
    }
    void reverse(string &s, int start, int end){
      while(start < end){
	char temp = s[start];
	s[start] = s[end];
	s[end] = temp;
	start++;
	end--;
      }
      return;
    }
};

// v2
class Solution {
  public:
    void reverseWords(string &s) {
      // remove leading/trailing spaces
      if(s.size() == 0) return;
      while(s[0] == ' ') s.erase(0, 1);
      // reverse whole string
      reverse(s, 0, s.size() - 1);
      if(s.size() == 0) return;
      while(s[0] == ' ') s.erase(0, 1);
      // reverse each word
      int start = 0, end;
      for(int i = 0; i < s.size(); i++){
	if(s[i] == ' '){
	  end = i - 1;
	  reverse(s, start, end);
	  start = i + 1;
	}
      }
      end = s.size() - 1;
      reverse(s, start, end);
      // remove redundent spaces
      int i = 0;
      while(i < s.size() - 1){
	if(s[i] == ' ' && s[i + 1] == ' '){
	  s.erase(i, 1);
	  i--;
	}
	i++;
      }
    }
    void reverse(string& s, int i, int j){
      while(i < j){
	swap(s[i], s[j]);
	i++;
	j--;
      }
    }
};
