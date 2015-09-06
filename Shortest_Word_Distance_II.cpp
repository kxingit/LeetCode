/* 
 * Design a class which receives a list of words in the constructor, 
 * and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
 */
// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
class WordDistance {
  public:
    unordered_map<string, vector<int>> dict; // save indeces for each word
    WordDistance(vector<string>& words) {
      for(int i = 0; i < words.size(); i++){
	dict[words[i]].push_back(i);
      }
    }

    int shortest(string word1, string word2) {
      auto id1 = dict[word1];
      auto id2 = dict[word2];
      int i = 0, j = 0;
      int result = INT_MAX;
      while(i < id1.size() && j < id2.size()){
	int currmin = abs(id1[i] - id2[j]);
	result = min(result, currmin);
	if(id1[i] < id2[j]) i++;
	else j++;
      }
      return result;
    }
};
// v2
class WordDistance {
  public:
    WordDistance(vector<string>& words) {
      for(int i = 0; i < words.size(); i++){
	map[words[i]].push_back(i);
      }
    }

    int shortest(string word1, string word2) {
      auto id1 = map[word1];
      auto id2 = map[word2];
      int i = 0, j = 0;
      int result = INT_MAX;
      while(i < id1.size() && j < id2.size()){
	int currmin = abs(id1[i] - id2[j]);
	result = min(result, currmin);
	if(id1[i] < id2[j]) i++;
	else j++;
      }
      return result;
    }
    unordered_map<string, vector<int>> map;
};

