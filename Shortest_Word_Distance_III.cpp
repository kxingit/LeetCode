/*
 * This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
 */
class Solution {
  public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
      int result = INT_MAX;
      if(word1 != word2){
	int id1 = -1, id2 = -1;
	for(int i = 0; i < words.size(); i++){
	  if(words[i] == word1 || words[i] == word2){
	    if(words[i] == word1) id1 = i;
	    else if(words[i] == word2) id2 = i;
	    if(id1 != -1 && id2 != -1){
	      int currmin = abs(id1 - id2);
	      result = min(result, currmin);
	    }
	  }
	}
	return result;
      }
      else{ // word1 == word2
	int id = -1, preid = -1;
	for(int i = 0; i < words.size(); i++){
	  if(words[i] == word1){
	    id = i;
	    if(id != -1 && preid != -1){
	      int currmin = abs(id - preid);
	      result = min(result, currmin);
	    }
	    preid = id;
	  }
	}
	return result;
      }
    }
};
// v2
class Solution {
  public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
      int p1 = -1, p2 = -1;
      int result = INT_MAX;
      if(word1 != word2) {
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
      }
      else { // word1 == word2
	for(int i = 0; i < words.size(); i++) {
	  if(word1 == words[i]) {
	    p2 = i;
	    if(p1 != -1 && p2 != -1) result = min(result, abs(p2 - p1));
	    p1 = p2;
	  }
	}
      }
      return result;
    }
};
