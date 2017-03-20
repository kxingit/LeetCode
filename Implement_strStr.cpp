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
};

// v3
class Solution {
public:
    int strStr(string s, string t) {
        // 7:24 - 7:33
        if(t.size() == 0) return 0;
        if(s.size() == 0) return -1;
        for(int i = 0; i < s.size(); i++) {
            if(i + t.size() - 1 > s.size()) continue;
            for(int j = 0; j < t.size(); j++) {
                if(s[i + j] != t[j]) break;
                if(j == t.size() - 1) return i;
            }
        }
        return -1;
    }
};
