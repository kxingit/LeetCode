class Solution {
  public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
      // BFS: Breadth-First-Search
      queue <pair<string, int>> q; // word and level number
      q.push(make_pair(start, 1));
      unordered_set<string> visited;
      // Each element is inserted only if it is not equivalent to any other element already in the container
      visited.insert(start);

      while(!q.empty()){
	pair<string, int> curr= q.front();
	q.pop();
	string word = curr.first;
	for(int i = 0; i < word.size(); i++){
	  string newWord(word); // reset string in the next cycle
	  for(int j = 0; j < 26; j++){ // loop from 0, i.e. 'a'
	    newWord[i] = 'a' + j;
	    if(newWord == end) return curr.second + 1;
	    if(dict.count(newWord) > 0 && visited.count(newWord) == 0){
	      q.push(make_pair(newWord, curr.second + 1));
	      visited.insert(newWord);
	    }
	  }
	}
      }
      return 0;

    }
};
