/* 
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
 */

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      if(digits.size() == 0) return res;
      string tmpres;
      dfs(digits, 0, tmpres, res);
      return res;
    }
  private:
    string numap[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // index: index for each number.
    void dfs(const string &digits, int index, string &tmpres, vector<string>&res)
    {
      if(index == digits.size())
      {
	res.push_back(tmpres);
	return;
      }
      for(int i = 0; i < numap[digits[index] - '0'].size(); i++)
      {
	tmpres.push_back(numap[digits[index] - '0'][i]);
	dfs(digits, index + 1, tmpres, res);
	tmpres.pop_back();
      }
    }
};
