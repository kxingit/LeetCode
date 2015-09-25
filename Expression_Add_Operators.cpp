/*
 * Given a string that contains only digits 0-9 and a target value, 
 * return all possibilities to add binary operators (not unary) +, -, 
 * or * between the digits so they evaluate to the target value.
 */
class Solution {
  public:
    vector<string> addOperators(string num, int target) {
      vector<string> res;
      addOperatorsDFS(num, target, 0, 0, "", res);
      return res;
    }
    void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
      if (num.size() == 0 && curNum == target) {
	res.push_back(out);
      }
      for (int i = 1; i <= num.size(); ++i) {
	string cur = num.substr(0, i);
	if (cur.size() > 1 && cur[0] == '0') return;
	string next = num.substr(i);
	if (out.size() > 0) {
	  addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
	  addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
	  addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
	} else {
	  addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
	}
      }
    }
};
// v2
class Solution {
  public:
    vector<string> addOperators(string num, int target) {
      vector<string> result;
      dfs(num, target, 0, 0, 0, "", result);
      return result;
    }
    void dfs(string &num, int target, int start, long curSolution, long diff, string solution, vector<string> &result) {
      if(start == num.size()) {
	if(curSolution == target) result.push_back(solution);
	return;
      }
      for(int i = start; i < num.size(); i++) {
	if(i - start > 0 && num[start] == '0') return;
	long curNum = stoll(num.substr(start, i - start + 1));
	if(solution.size() == 0) {
	  dfs(num, target, i + 1, curNum, curNum, to_string(curNum), result);
	}
	else {
	  dfs(num, target, i + 1, curSolution + curNum, curNum, solution + "+" + to_string(curNum), result);
	  dfs(num, target, i + 1, curSolution - curNum, -1 * curNum, solution + "-" + to_string(curNum), result);
	  dfs(num, target, i + 1, (curSolution - diff) + diff * curNum, diff * curNum, solution + "*" + to_string(curNum), result);
	}
      }
    }
};
