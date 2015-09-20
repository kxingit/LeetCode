/*
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 */
class Solution {
  public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
      int index1 = -1, index2 = -1;
      int result = INT_MAX;
      for(int i = 0; i < words.size(); i++){
	if(words[i] == word1 || words[i] == word2){
	  if(word1 == words[i]) index1 = i;
	  else if(word2 == words[i]) index2 = i;
	  if(index1 != -1 && index2 != -1){
	    int currmin = abs(index1 - index2);
	    result = min(result, currmin);
	  }
	}
      }
      return result;
    }
};
// v2
class Solution {
  public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
      int p1 = -1, p2 = -1;
      int result = INT_MAX;
      for(int i = 0; i < words.size(); i++) {
	if(word1 == words[i]) {
	  p1 = i;
	  if(p2 != -1) result = min(result, abs(p1 - p2));
	}
	else if(word2 == words[i]) { 
	  p2 = i;
	  if(p1 != -1)result = min(result, abs(p1 - p2));
	}
      }
      return result;
    }
};
