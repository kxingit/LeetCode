/*
   Count and Say Total Accepted: 49223 Total Submissions: 194352 My Submissions Question Solution 
   The count-and-say sequence is the sequence of integers beginning as follows:
   1, 11, 21, 1211, 111221, ...

   1 is read off as "one 1" or 11.
   11 is read off as "two 1s" or 21.
   21 is read off as "one 2, then one 1" or 1211.
   Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
 */
// time limit exceeded

class Solution {
  public:
    string countAndSay(int n) {
      string s = "1";
      for(int i = 0; i < n; i++){
	int count = 1;
	string news = "";
	for(int j = 0; j < s.size(); j++){
	  if(j == s.size() - 1){
	    news = news + to_string(count * 10 + s[j]);
	  }
	  else if(s[j] == s[j + 1]){
	    count++;
	  }
	  else if(s[j] != s[j + 1]){
	    news = news + to_string(count * 10 + s[j]);
	    count = 1;
	  }
	}
	s = news;
      }
      return s;
    }
};
