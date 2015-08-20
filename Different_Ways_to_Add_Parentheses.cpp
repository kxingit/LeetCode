/* 
 * Given a string of numbers and operators,
 * return all possible results from computing all the different possible
 * ways to group numbers and operators. The valid operators are +, - and *.
 */
class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
      vector<int> result;
      int n = input.size();
      for(int i = 0; i < n; i++){
	if(input[i] == '+' || input[i] == '-' || input[i] == '*') break;
	if(i == n - 1){
	  result.push_back(stoi(input));
	  return result;
	}
      }
      for(int i = 0; i < n; i++){
	if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
	  vector<int> left = diffWaysToCompute(input.substr(0, i));
	  vector<int> right = diffWaysToCompute(input.substr(i + 1, n - 1 - i));
	  for(int j = 0; j < left.size(); j++){
	    for(int k = 0; k < right.size(); k++){
	      int solution = 0;
	      if(input[i] == '+') solution = left[j] + right[k];
	      if(input[i] == '-') solution = left[j] - right[k];
	      if(input[i] == '*') solution = left[j] * right[k];
	      result.push_back(solution);
	    }
	  }
	}
      }
      return result;
    }
};
