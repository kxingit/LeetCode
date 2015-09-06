/*
 * tag
 * Given a string s, return all the palindromic permutations (without duplicates) of it. 
 * Return an empty list if no palindromic permutation could be form.
 */
// Memory Limit Exceeded
class Solution {
  public:
    vector<string> generatePalindromes(string s) {
      unordered_map<char, int> map;
      bool hasCenter = false;
      for(int i = 0; i < s.size(); i++){
	map[s[i]]++;
      }
      string solution;
      char center;
      for(auto w : map){
	int count = w.second;
	if(count & 1) {
	  center = w.first; // find center
	  hasCenter = true;   
	}
	while(count >= 2){
	  solution.insert(solution.end(), w.first);
	  count -= 2;
	}
      }
      vector<string> result; // sec half
      genPerm(solution, result);
      for(auto &s : result){
	string firsthalf(s);
	reverse(firsthalf.begin(), firsthalf.end());
	if(hasCenter) s = center + s;
	s = firsthalf + s;
      }
      return result;
    }
    void genPerm(string &s, vector<string> &result){
      string temp(s);
      do{
	result.push_back(temp);
	next_permutation(temp.begin(), temp.end());
      } while (temp != s);
    }
};
// v2
class Solution {
  public:
    vector<string> generatePalindromes(string s) {
      vector<string> palindromes;
      unordered_map<char, int> counts;
      for (char c : s) counts[c]++;
      int odd = 0; char mid; string half;
      for (auto p : counts) {
	if (p.second & 1) {
	  odd++, mid = p.first;
	  if (odd > 1) return palindromes;
	}
	half += string(p.second / 2, p.first);
      }
      palindromes = permutations(half);
      for (string& p : palindromes) {
	string t(p);
	reverse(t.begin(), t.end());
	if (odd) t = mid + t;
	p += t;
      }
      return palindromes;
    }
  private: 
    vector<string> permutations(string& s) {
      vector<string> perms;
      string t(s);
      do {
	perms.push_back(s);
	next_permutation(s.begin(), s.end());
      } while (s != t);
      return perms;
    }
};
