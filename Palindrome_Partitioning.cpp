class Solution {
  public:
    vector<vector<string>> partition(string s) {
      vector<string> output;
      vector<vector<string>> result;
      DFS(s, 0, output, result);
      return result;
    }
    void DFS(string &s, int start, vector<string>& output, vector<vector<string>>& result){
      if(start == s.size()){
	result.push_back(output);
	return; 
      }
      for(int i = start; i < s.size(); i++){
	if(isPal(s, start, i)){ 
	  output.push_back(s.substr(start, i - start + 1));
	  DFS(s, i + 1, output, result);
	  output.pop_back(); // reset after recursion, before the next loop
	}
      }
    }
    bool isPal(string &s, int start, int end){
      while(start < end){
	if(s[start] != s[end]) return false;
	start++;
	end--;
      }
      return true;
    }
};
// v2
class Solution {
  public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> result;
      vector<string> solution;
      part(s, 0, solution, result);
      return result;
    }
    void part(string &s, int start, vector<string> &solution, vector<vector<string>> &result) {
      if(start == s.size()) {
	result.push_back(solution);
	return;
      }
      for(int i = start; i < s.size(); i++) {
	if(isPal(s, start, i)) {
	  solution.push_back(s.substr(start, i - start + 1));
	  part(s, i + 1, solution, result);
	  solution.pop_back();
	}
      }
    }
    bool isPal(string &s, int i, int j) {
      while(i < j) {
	if(s[i] != s[j]) return false;
	i++;
	j--;
      }
      return true;
    }
};
