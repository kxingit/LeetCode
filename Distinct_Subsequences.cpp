/*
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 */
class Solution {
  public:
    int numDistinct(string S, string T) {
      int match[T.size()];
      if(S.size() < T.size()) return 0;
      match[0] = 1;
      for(int i = 1; i <= T.size(); i++) match[i] = 0;
      for(int i = 1; i <= S.size(); i++){
	for(int j = T.size(); j >= 1; j--){
	  if(S[i - 1] == T[j - 1])
	    match[j] += match[j - 1];
	}
      }
      return match[T.size()];
    }
};
// v2
class Solution {
  public:
    int numDistinct(string s, string t) {
      int m = s.size();
      int n = t.size();
      if(!m || !n) return 0;
      vector<vector<int>> match(m + 1, vector<int>(n + 1, 0));
      // initialization
      for(int i = 0; i <= m; i++){
	match[i][0] = 1;
      }
      for(int j = 0; j <= n; j++){
	match[0][j] = 0;
      }
      match[0][0] = 1;
      // dp
      for(int i = 1; i <= m; i++){
	for(int j = 1; j <= n; j++){
	  if(s[i - 1] != t[j - 1]){
	    match[i][j] = match[i - 1][j];
	  }
	  else{
	    match[i][j] = match[i - 1][j] + match[i - 1][j - 1];
	  }
	}
      }
      return match[m][n];
    }
};
