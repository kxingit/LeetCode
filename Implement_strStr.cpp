<<<<<<< HEAD
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
=======
/*
 *  Implement strStr().
 *
 *  Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
 */
class Solution {
  public:
	int strStr(string s, string t) {
	  int n = s.size(), m = t.size();
	  if(!m) return 0;
	  for(int i = 0; i < n; i++) {
		if(i + m > n) return -1;
		for(int j = 0; j < m; j++) {
		  if(s[i + j] != t[j]) break;
		  if(j == m - 1) return i;
		}
	  }
	  return -1;
	}
>>>>>>> 02f885fa68d0c2068268dd99680d613b20f243ac
};
