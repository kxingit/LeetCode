/*
 * Implement regular expression matching with support for '.' and '*'.
 */
class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
      if (*p == '\0') return *s == '\0';

      // next char is not '*', then must match current char
      if (*(p+1) != '*'){
	if (*p == *s || (*p == '.' && *s != '\0')) // if the current char match
	  return isMatch(s + 1, p + 1);   // move to the next
	else
	  return false;
      } else { // next char is '*'
	while (*p == *s || (*p == '.' && *s != '\0')){ // if the current char match
	  if (isMatch(s, p + 2))  // ????
	    return true;
	  s++;
	}
	return isMatch(s, p +2);
      }
    }
};
// v2
class Solution {
  public:
    bool isMatch(string s, string p) {
      return isM(s, 0, p, 0); // match starting from 0
    }
    bool isM(string &s, int i, string &p, int j){
      if(j >= p.size()) return i >= s.size();
      if(j + 1 < p.size() && p[j + 1] == '*'){
	while(i < s.size() && (p[j] == '.' || p[j] == s[i])){
	  if(isM(s, i, p, j + 2)) return true;
	  i++;
	}
	return isM(s, i, p, j + 2);
      }
      else if(i < s.size() && (p[j] == '.' || p[j] == s[i])){
	return isM(s, i + 1, p, j + 1);
      }
      return false;
    }
};
// v3
class Solution {
  public:
    bool isMatch(string s, string p) {
      return isM(s, 0, p, 0);
    }
    bool isM(string &s, int i, string &p, int j){
      if(j >= p.size()) return i >= s.size();
      if(j + 1 < p.size() && p[j + 1] == '*'){
	while(i < s.size() && (p[j] == '.' || p[j] == s[i])){
	  if(isM(s, i, p, j + 2)) return true; // no return if false
	  i++;
	}
	return isM(s, i, p, j + 2); // trailing '*'
      }
      else if(i < s.size() && (p[j] == s[i] || p[j] == '.')){
	return isM(s, i + 1, p, j + 1);
      }
      return false;
    }
};
// v4
class Solution {
  public:
    bool isMatch(string s, string p) {
      return isM(s, 0, p, 0);
    }
    bool isM(string &s, int i, string &p, int j){
      if(j >= p.size()) return i >= s.size(); // if cover entire
      if(j + 1 < p.size() && p[j + 1] == '*'){
	if(isM(s, i + 1, p, j + 1)) return true; // wrong
	while(i < s.size() && (s[i] == p[j] || p[j] == '.')){
	  if(isM(s, i, p, j + 2)) return true;
	  i++;
	}
	return isM(s, i, p, j + 2); // trailing '*'
      }
      else if(i < s.size() && (s[i] == p[j] || p[j] == '.')){
	return isM(s, i + 1, p, j + 1);
      }
      return false;
    }
};
// v5 
class Solution {
  public:
    bool isMatch(string s, string p) {
      return isM(s, 0, p, 0);
    }
    bool isM(string &s, int i, string &p, int j){
      if(j >= p.size()) return i >= s.size(); // if covered
      if(j + 1 < p.size() && p[j + 1] == '*'){
	while(i < s.size() && (s[i] == p[j] || p[j] == '.')){
	  if(isM(s, i, p, j + 2)) return true;
	  i++;
	}
	return isM(s, i, p, j + 2);
      }
      else if(i < s.size() && (s[i] == p[j] || p[j] == '.')){
	return isM(s, i + 1, p, j + 1);
      }
      return false;
    }
};
// v6
class Solution {
  public:
    bool isMatch(string s, string p) {
      return isM(s, 0, p, 0);
    }
    bool isM(string &s, int i, string& p, int j){
      if(j >= p.size()) return i >= s.size();
      if(j + 1 < p.size() && p[j + 1] == '*'){
	while(i < s.size() && (p[j] == '.' || p[j] == s[i])){
	  if(isM(s, i, p, j + 2)) return true;
	  i++;
	}
	return isM(s, i, p, j + 2);
      }
      else if(i < s.size() && (p[j] == '.' || p[j] == s[i])){
	return isM(s, i + 1, p, j + 1);
      }
      return false;
    }
};
// v7
class Solution {
  public:
    bool isMatch(string s, string p) {
      return isM(s, 0, p, 0);
    }
    bool isM(string &s, int i, string &p, int j){
      if(j >= p.size()) return i >= s.size();
      if(j + 1 < p.size() && p[j + 1] == '*'){
	while(i < s.size() && (s[i] == p[j] || p[j] == '.')){
	  if(isM(s, i, p, j + 2)) return true;
	  i++;
	}
	return isM(s, i, p, j + 2);
      }
      else if(i < s.size() && (s[i] == p[j] || p[j] == '.')){
	return isM(s, i + 1, p, j + 1);
      }
      return false;
    }
};
