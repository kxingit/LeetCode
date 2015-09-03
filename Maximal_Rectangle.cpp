/*
 * Given a 2D binary matrix filled with 0's and 1's, 
 * find the largest rectangle containing all ones and return its area.
 */
class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int m = matrix.size();
      if(!m) return 0;
      int n = matrix[0].size();
      int result = 0;
      vector<vector<int>> hist(m, vector<int>(n, 0)); // hist per line
      for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++){
	  if(i == 0){
	    hist[i][j] = matrix[i][j] == '0' ? 0 : 1;
	    continue;
	  }
	  if(matrix[i][j] == '0'){
	    hist[i][j] = 0;
	  }
	  else{
	    hist[i][j] = hist[i - 1][j] + 1;
	  }
	}
      }
      for(int i = 0; i < m; i++){
	result = max(result, histMaxRectangle(hist[i]));
      }
      return result;
    }
    int histMaxRectangle(vector<int>& h){
      int result = 0;
      h.push_back(0);
      stack<int> s; // save increasing indeces
      for(int i = 0; i < h.size(); i++){
	if(s.empty() || h[i] > h[s.top()]) s.push(i);
	else{
	  int tmpi = s.top();
	  s.pop();
	  int width = s.empty() ? i : i - s.top() - 1;
	  result = max(result, h[tmpi] * width);
	  i--; // try new stack top
	}
      }
      return result;
    }
};
// v2
class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int m = matrix.size();
      if(!m) return 0;
      int n = matrix[0].size();
      vector<vector<int>> hist(m, vector<int>(n, 0));
      for(int i = 0; i < m; i++){
	for(int j = 0; j < n; j++){
	  if(i == 0){
	    hist[i][j] = matrix[i][j] == '0' ? 0 : 1;
	  }
	  else{
	    hist[i][j] = matrix[i][j] == '0' ? 0 : hist[i - 1][j] + 1;
	  }
	}
      }
      int result = 0;
      for(int i = 0; i < m; i++){
	result = max(result, maxRec(hist[i]));
      }
      return result;
    }
    int maxRec(vector<int>& h){
      h.push_back(0);
      stack<int> s; // save increasing indeces
      int result = 0;
      for(int i = 0; i < h.size(); i++){
	if(s.empty() || h[i] > h[s.top()]){ 
	  s.push(i);
	}
	else{
	  int curh = h[s.top()]; // current height
	  s.pop();
	  int width = s.empty() ? i : i - s.top() - 1;
	  result = max(result, curh * width);
	  i--;
	}
      }
      return result;
    }
};
