/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> result;
      gen(n, 0, 0, "", result);
      return result;
    }
    void gen(int n, int l, int r, string s, vector<string> &result) {
      if(l == n) {
	s.append(n - r, ')');
	result.push_back(s);
	return;
      }
      gen(n, l + 1, r, s + "(", result);
      if(l > r) gen(n, l, r + 1, s + ")", result);
    }
};
