Solution {
  public:
    int minDistance(string word1, string word2) {
      int w1l = word1.size();
      int w2l = word2.size();
      // if(w1l == 0) return w2l;
      // if(w2l == 0) return w1l;

      int dp[w1l + 1][w2l + 1];
      for(int i = 0; i <= w1l; i++) dp[i][0] = i;
      for(int j = 0; j <= w2l; j++) dp[0][j] = j;

      for(int i = 1; i <= w1l; i++){
	for(int j = 1; j <= w2l; j++){
	  if(word1[i - 1] == word2[j - 1]){
	    dp[i][j] = dp[i -1][j - 1];
	  } else{
	    dp[i][j] = 1 + min(min(dp[i -1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
	  }
	}
      }
      return dp[w1l][w2l];
    }
};
